## Why

The project needs its own Unreal gameplay framework classes as a clear foundation for game-wide and per-player behavior. Adding the four base classes now establishes consistent extension points before game logic and multiplayer state are built on top of them.

## What Changes

- Add `AACGameMode` and `AACGameState` with headers in `Source/FGOAutoChess/Public/Game/` and implementations in `Source/FGOAutoChess/Private/Game/`.
- Add `AACPlayerController` and `AACPlayerState` with headers in `Source/FGOAutoChess/Public/Player/` and implementations in `Source/FGOAutoChess/Private/Player/`.
- Derive each class from its matching Unreal Engine framework base class and expose standard generated-header/UObject declarations.
- Keep behavior minimal so the classes can serve as project-owned extension points.

## Capabilities

### New Capabilities
- `game-player-framework`: Project-owned GameMode, GameState, PlayerController, and PlayerState classes are available as gameplay extension points.

### Modified Capabilities

## Impact

- Adds public headers under `Source/FGOAutoChess/Public/Game` and `Source/FGOAutoChess/Public/Player`, plus implementations under `Source/FGOAutoChess/Private/Game` and `Source/FGOAutoChess/Private/Player`.
- May require setting project defaults in configuration only if that is part of the intended implementation; this proposal does not require changing the active map or game defaults.
- No new module dependency is expected; the existing module already depends on Core, CoreUObject, and Engine.
