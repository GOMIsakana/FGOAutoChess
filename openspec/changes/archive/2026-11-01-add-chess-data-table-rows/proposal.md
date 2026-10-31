# Proposal

## Why

The project needs a consistent, designer-configurable data shape for chess pieces, classes, skills, and effects. Defining these as Unreal DataTable row types gives future gameplay and content work a stable schema to build on.

## What Changes

- Add DataTable row structures for chess, class, skill, and effect data.
- Add an `EEffectType` placeholder enum containing only `None`.
- Keep this change limited to data definitions; it adds no runtime combat, skill-trigger, or effect-execution behavior.

## Capabilities

### New Capabilities
- `chess-data-tables`: DataTable-compatible row definitions for chess content and effect type metadata.

### Modified Capabilities

## Impact

- Affected code: new public C++ data definitions in the `FGOAutoChess` runtime module.
- Uses Unreal reflection types including `FText`, `FGameplayTag`, and DataTable row support.
- No new module dependency is expected; the runtime module already depends on GameplayTags.
- No assets or existing DataTable content are changed by this definition-only change.
