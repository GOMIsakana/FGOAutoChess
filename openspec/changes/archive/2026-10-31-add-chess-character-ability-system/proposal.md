# Proposal

## Why

The project needs a project-owned character type and Ability System Component as stable extension points for chess-unit gameplay. Providing these classes in the runtime module establishes a consistent place to add character and ability behavior as the project grows.

## What Changes

- Add a Blueprint-extendable project character class `AACChess` derived from `ACharacter` under the `Character` source folders. It implements `IAbilitySystemInterface` and owns a protected `UACAbilitySystemComponent` returned by `GetAbilitySystemComponent()`.
- Add a project Ability System Component class `UACAbilitySystemComponent` derived from `UAbilitySystemComponent` under the `AbilitySystem` source folders.
- Add the Gameplay Ability System module dependency required to compile the component.
- Keep both classes as minimal project extension points without adding abilities, attributes, or gameplay effects.

## Capabilities

### New Capabilities

- `chess-character-ability-system`: Project-specific character and ability-system component base classes.

### Modified Capabilities

None.

## Impact

- Runtime module headers and implementations under `Source/FGOAutoChess/Public/Character/`, `Private/Character/`, `Public/AbilitySystem/`, and `Private/AbilitySystem/`.
- `Source/FGOAutoChess/FGOAutoChess.Build.cs` for GameplayAbilities module dependency.
- Unreal Header Tool and runtime module compilation for the new reflected classes.
