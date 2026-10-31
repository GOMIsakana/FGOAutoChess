# Spec Delta

## ADDED Requirements

### Requirement: Chess units have a shared ability attribute set
The project SHALL provide a `UChessAttributeSet` type under the AbilitySystem source folders as a reusable Gameplay Ability System attribute set for chess-unit combat attributes.

#### Scenario: Attribute set is available to runtime code
- **WHEN** the FGOAutoChess runtime module is compiled
- **THEN** runtime code can include and use `UChessAttributeSet` as a Gameplay Ability System attribute set

### Requirement: Chess attribute set defines core combat attributes
`UChessAttributeSet` SHALL define the `MaxHealth`, `Health`, `Attack`, `Shield`, and `Speed` attributes for Gameplay Ability System use.

#### Scenario: Core attributes are available
- **WHEN** gameplay code or a gameplay effect accesses a chess unit's attribute set
- **THEN** it can read and update MaxHealth, Health, Attack, Shield, and Speed as GAS attributes

#### Scenario: Core attributes replicate to clients
- **WHEN** a server-authoritative chess unit's core attribute changes
- **THEN** the changed attribute value is replicated to clients through the Gameplay Ability System

#### Scenario: Attribute set does not impose combat rules
- **WHEN** the attribute set is used
- **THEN** it does not define default values, clamping, damage handling, or other combat calculations
