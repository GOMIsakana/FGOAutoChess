## Context

The project uses one Unreal Engine 5.6 runtime module, `FGOAutoChess`, with the standard `Core`, `CoreUObject`, and `Engine` dependencies. It does not yet have project-owned gameplay framework classes. Public headers belong under `Source/FGOAutoChess/Public/`; private implementations belong under `Source/FGOAutoChess/Private/`.

## Goals / Non-Goals

**Goals:**
- Add four minimal, Blueprint-extendable Unreal gameplay framework classes, placing headers under `Public/Game/` or `Public/Player/` and implementations under the matching `Private/` subdirectory.
- Preserve Unreal's reflected type naming conventions: `AACGameMode`, `AACGameState`, `AACPlayerController`, and `AACPlayerState` (the leading `A` is the Unreal actor-class prefix; the project class names are `ACGameMode`, `ACGameState`, `ACPlayerController`, and `ACPlayerState`).
- Keep the existing project defaults unchanged unless implementation specifically requires otherwise.

**Non-Goals:**
- Add gameplay rules, replicated properties, input bindings, UI, or asset references.
- Change maps, GameMode defaults, or project configuration.
- Create separate Unreal modules.

## Decisions

- Put GameMode and GameState headers in `Source/FGOAutoChess/Public/Game/` and their `.cpp` files in `Source/FGOAutoChess/Private/Game/`. Put PlayerController and PlayerState headers in `Source/FGOAutoChess/Public/Player/` and their `.cpp` files in `Source/FGOAutoChess/Private/Player/`. These are standard public/private module source roots; no module restructuring is needed.
- Derive the classes from `AGameModeBase`, `AGameStateBase`, `APlayerController`, and `APlayerState`, respectively. The base variants provide the standard framework roles without adding legacy match rules or behavior.
- Use standard `UCLASS(Blueprintable)` declarations and generated headers so designers can make Blueprint subclasses while keeping the C++ types minimal.
- Use Unreal's `A` reflected class prefix, resulting in C++ identifiers such as `AACGameMode`; this represents the requested project type name `ACGameMode` and avoids invalid UObject naming conventions.
- Do not set these classes as project defaults. This keeps the addition isolated and avoids changing existing map or project behavior.

## Risks / Trade-offs

- [The requested names can be read as literal C++ identifiers.] → Record the Unreal `A` prefix convention explicitly; use `AAC...` identifiers for the requested `AC...` actor class names.
- [New classes are not active until selected by a map or project default.] → Treat activation as out of scope; this change only supplies the framework extension points.
