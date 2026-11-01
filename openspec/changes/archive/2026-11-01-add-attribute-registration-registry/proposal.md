# Proposal

## Why

Gameplay code needs a stable way to identify GAS attributes by numeric ID and GameplayTag, but the project currently only exposes attribute accessors and has no central registry. A shared registry will make attribute definitions discoverable in editor settings and provide deterministic runtime lookup for current and future AttributeSets.

## What Changes

- Add a reusable `UACAttributeSetBase` with per-attribute static Tag/ID accessors; its additional constructor behavior registers attribute GameplayTags only.
- Add configurable AttributeSet class selection and an import trigger to `UAttributeSettings`; when the trigger changes, import selected classes into the generated read-only `AttributeInfo` list and save the result to config.
- Register each attribute with a fixed ID and a native GameplayTag named `Attributes.XXX`, where `XXX` is the property name.
- Add `UAttributeRegisterSubsystem` to copy registration data at runtime and query full registration records by ID, `FGameplayAttribute`, or `FGameplayTag`.
- Make imports idempotent by rebuilding the generated list from the configured class set; validate duplicates, log an error, and ignore later conflicting entries.
- Assign non-overlapping ID ranges per AttributeSet; Chess uses 1000-1999 and future Projectile attributes use 2000-2999.

## Capabilities

### New Capabilities

- `gameplay-attribute-registry`: Defines explicit registration, editor-visible attribute metadata, stable identifiers, GameplayTag mapping, and runtime lookup behavior.

### Modified Capabilities

None.

## Impact

- Adds shared AbilitySystem attribute registration types and macros in the FGOAutoChess runtime module.
- Adds a DeveloperSettings dependency for the editor-visible settings class while continuing to use existing GameplayAbilities and GameplayTags dependencies.
- Extends the current Chess attribute declarations with fixed IDs and registers the five existing attributes.
