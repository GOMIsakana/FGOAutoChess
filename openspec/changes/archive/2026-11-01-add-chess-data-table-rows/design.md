# Design

## Context

The runtime module already depends on GameplayTags, and its existing attribute set uses `FGameplayAttributeData`. No chess, class, skill, effect row types or `EEffectType` enum currently exist. See proposal.md for motivation and `specs/chess-data-tables/spec.md` for the required row fields.

## Goals / Non-Goals

**Goals:**
- Provide reflected, editor-editable row types that Unreal DataTables can use.
- Keep the requested field names and types stable for downstream gameplay code.

**Non-Goals:**
- Implement attribute mapping, skill scheduling, effect execution, combat calculations, or data validation.
- Add concrete effect types beyond the `None` placeholder.
- Create or migrate DataTable assets.

## Decisions

- Define the four structs as `USTRUCT(BlueprintType)` rows deriving from `FTableRowBase`, with the requested fields exposed as editable reflected properties. This allows Unreal's DataTable editor and runtime row APIs to use them; plain C++ structs would not provide that integration.
- Keep each explicit ID field (`ChessId`, `ClassId`, `SkillId`, `EffectId`) even though a DataTable also has a row name. The IDs are part of the requested schema and allow references between rows to remain numeric.
- Use `TMap<FGameplayTag, float>` for chess attributes and `TMap<int32, float>` for class matchup multipliers as specified. No DevelopmentSettings mapping layer is part of this schema.
- Declare `EEffectType` as a reflected `uint8` enum with only `None`, colocated with the effect row schema. Future effect kinds can extend it when their behavior is designed.
- Place the definitions under `Source/FGOAutoChess/Public/Types/` and split them into `ChessData.h`, `ClassData.h`, `SkillData.h`, and `EffectData.h`. This keeps each public type focused and easy for gameplay code to include independently.
- Declare `EEffectType` in `EffectData.h` alongside `FEffectData`, since it is the effect row's type field and has no current users elsewhere.
- Treat array order as authored order and preserve it in the row values. The schema does not define how or when those IDs execute.

## Risks / Trade-offs

- `FString` effect parameters are weakly typed and can be malformed for future consumers -> keep parsing and validation out of this change, and define type-specific contracts when concrete effect types are added.
- Editor/import support for nested containers can differ by authoring path -> confirm DataTable editor authoring for the specified map and array properties when implementation is applied; the schema itself remains as requested.

## Migration Plan

No migration is required because this change introduces row types without changing existing assets or data.
