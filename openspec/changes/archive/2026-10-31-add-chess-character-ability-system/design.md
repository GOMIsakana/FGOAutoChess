# Design

## Context

The runtime module currently has a small set of project-specific framework classes under matching `Public/` and `Private/` folders. Its build rules do not currently list Gameplay Ability System modules. See proposal.md for motivation and the capability spec for the externally visible class contract.

## Goals / Non-Goals

**Goals:**
- Keep the new classes discoverable in the module's public API using the requested `Character/` and `AbilitySystem/` folder organization.
- Preserve them as minimal extension points that do not introduce abilities, attributes, or gameplay effects.

**Non-Goals:**
- Initialize an Ability System Component on a pawn or player state, grant abilities, or define attributes, gameplay effects, input bindings, or replication policy.
- Add a chess piece movement model or content assets.

## Decisions

- Place `AACChess` in `Public/Character/ACChess.h` and `Private/Character/ACChess.cpp`; derive it from `ACharacter`, implement `IAbilitySystemInterface`, and mark it Blueprintable, matching existing project framework classes.
- Place `UACAbilitySystemComponent` in `Public/AbilitySystem/ACAbilitySystemComponent.h` and `Private/AbilitySystem/ACAbilitySystemComponent.cpp`; derive it from `UAbilitySystemComponent` and keep it a plain reflected C++ class.
- Store the component in a protected `TObjectPtr<UACAbilitySystemComponent>` UPROPERTY on `AACChess`, create it with `CreateDefaultSubobject` in the character constructor, and return it from the interface's `GetAbilitySystemComponent()` override. This makes ownership explicit and ensures every character instance has the component.
- Add `GameplayAbilities`, `GameplayTags`, and `GameplayTasks` to the runtime module's public dependencies. The component's reflected base class references types and symbols from all three modules, and the dependency must be public for downstream code that includes the new public header.
- Keep constructors and class bodies minimal. Do not add ability grants, attribute sets, effects, or actor-info initialization policy as part of this change.

## Risks / Trade-offs

- [The target Unreal installation may not have the Gameplay Ability System plugin enabled] → Confirm the engine plugin is enabled for this project when implementing; enable it only if required for the module to compile.
- [The GAS public base type references symbols from multiple modules] → Keep the direct public dependencies limited to `GameplayAbilities`, `GameplayTags`, and `GameplayTasks`, which are required to compile and link the public component type.

## Migration Plan

No migration is required. Add the classes and module dependency, then compile the runtime module. Rollback consists of removing the two class pairs and the added module dependency.
