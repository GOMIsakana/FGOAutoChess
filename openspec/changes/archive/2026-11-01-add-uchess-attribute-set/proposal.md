# Proposal

## Why

The project has a base Gameplay Ability System component but no shared attribute set for chess units. A common attribute set gives abilities and gameplay effects a consistent place to read and update the core combat values.

## What Changes

- Add a `UChessAttributeSet` extension point under the AbilitySystem source folders.
- Define MaxHealth, Health, Attack, Shield, and Speed as GAS attributes.
- Document the attribute set as data only; gameplay rules such as damage handling, clamping, and default values are outside this change.

## Capabilities

### New Capabilities

None.

### Modified Capabilities

- `chess-character-ability-system`: Add the shared chess-unit attribute set and its five attributes.

## Impact

- Adds a C++ `UAttributeSet` type in `Source/FGOAutoChess/Public/AbilitySystem` with implementation in `Private/AbilitySystem`.
- Uses the existing Gameplay Ability System dependencies already declared by the runtime module.
- Exposes five attributes for runtime GAS use; no change to the existing chess character or ability-system component behavior is required.
