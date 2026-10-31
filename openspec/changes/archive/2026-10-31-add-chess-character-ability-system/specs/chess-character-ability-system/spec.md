# Spec Delta

## Purpose

Defines the project's reusable chess character and ability-system component base types, so gameplay code and designers have consistent extension points for future unit abilities.

## ADDED Requirements

### Requirement: Project chess character base class
The project SHALL provide a Blueprint-extendable C++ character class named `AACChess` derived from `ACharacter` in the `FGOAutoChess` runtime module.

#### Scenario: Chess character is available to runtime code
- **WHEN** the `FGOAutoChess` runtime module is compiled
- **THEN** runtime code can include the project chess character header and use `AACChess` as an `ACharacter`

#### Scenario: Chess character supports Blueprint extension
- **WHEN** a designer creates a Blueprint subclass from `AACChess`
- **THEN** the Blueprint can use the class as a parent without requiring additional ability, attribute, or gameplay-effect behavior from this change

### Requirement: Chess character provides its ability system component
`AACChess` SHALL implement `IAbilitySystemInterface`, own a protected `UACAbilitySystemComponent`, and return that component from `GetAbilitySystemComponent()`.

#### Scenario: Chess character creates and exposes its component
- **WHEN** an `AACChess` instance is constructed
- **THEN** it owns a `UACAbilitySystemComponent` and `GetAbilitySystemComponent()` returns that instance's component

#### Scenario: Ability system interface returns the owned component
- **WHEN** code queries the character through `IAbilitySystemInterface`
- **THEN** the returned `UAbilitySystemComponent` is the same component owned by `AACChess`

### Requirement: Project ability system component base class
The project SHALL provide a C++ class named `UACAbilitySystemComponent` derived from `UAbilitySystemComponent` in the `FGOAutoChess` runtime module.

#### Scenario: Ability system component is available to runtime code
- **WHEN** the `FGOAutoChess` runtime module is compiled with Gameplay Ability System support
- **THEN** runtime code can include the project component header and use `UACAbilitySystemComponent` as a `UAbilitySystemComponent`

#### Scenario: Component remains a behavior-free extension point
- **WHEN** the project uses `UACAbilitySystemComponent`
- **THEN** it provides the base Gameplay Ability System component behavior without imposing additional ability or attribute behavior in this change
