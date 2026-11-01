# Design

## Context

See proposal.md - Why. The runtime module already depends on GameplayAbilities and has its project component base class in `Public/AbilitySystem` and `Private/AbilitySystem`.

## Goals / Non-Goals

**Goals:**
- Follow Unreal's `UAttributeSet` pattern and make each requested value usable as a GAS attribute.
- Keep the type independently reusable by chess-unit gameplay code.

**Non-Goals:**
- Attaching or initializing the set on `AACChess` or changing its ownership model.
- Defining gameplay-effect calculations, default values, health constraints, or damage behavior.

## Decisions

- Implement `UChessAttributeSet` as a `UAttributeSet` subclass, with its public declaration in `Public/AbilitySystem/ChessAttributeSet.h` and module implementation in `Private/AbilitySystem/ChessAttributeSet.cpp`. This follows the existing `UACAbilitySystemComponent` folder split; placing the new class in the private folder would prevent other runtime code from including it.
- Store each value as `FGameplayAttributeData` and expose standard GAS accessors using the project's existing module export macro. This follows GAS attribute conventions and supports gameplay effects and attribute captures. Plain numeric fields would not provide the expected GAS attribute interface.
- Replicate the five attribute properties with the standard GAS attribute replication pattern so server-authored combat values can be observed by clients. No replication condition or gameplay rule beyond normal attribute replication is introduced.
- Keep the attribute set as a standalone type. Automatically creating or initializing it on the chess character would couple this addition to ownership and lifecycle decisions that are not required for declaring the attributes.

## Risks / Trade-offs

- Attribute properties replicated without gameplay initialization may remain at their engine defaults until another system initializes them → leave initialization to the owning gameplay setup, as default values are outside this change.
- Replication declarations must follow Unreal's expected attribute replication and rep-notify conventions → use the standard GAS pattern consistently for all five properties.

## Migration Plan

No migration is required. Existing character and ability-system component users can adopt the attribute set when their gameplay setup is ready.
