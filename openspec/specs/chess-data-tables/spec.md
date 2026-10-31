# chess-data-tables Specification

## Purpose

Defines stable, editable DataTable row schemas for chess pieces, classes, skills, and effects so game content can be authored consistently and consumed by future runtime systems.

## Requirements

### Requirement: Chess data is represented by a DataTable row
The project SHALL provide a DataTable-compatible chess row containing `ChessId` (`int32`), `Name` (`FText`), `ClassId` (`int32`), `Attribute` (`TMap<FGameplayTag, float>`), `PrimarySkill` (`TArray<int32>`), and `PassiveSkill` (`TArray<int32>`).

#### Scenario: Chess row can describe a chess piece
- **WHEN** content authors create a chess row
- **THEN** they can configure its ID, localized name, class ID, tag-keyed numeric attributes, primary skill IDs, and passive skill IDs

### Requirement: Class data is represented by a DataTable row
The project SHALL provide a DataTable-compatible class row containing `ClassId` (`int32`), `Name` (`FText`), `AttackMultiply` (`TMap<int32, float>`), and `DefenseMultiply` (`TMap<int32, float>`).

#### Scenario: Class row can describe matchup multipliers
- **WHEN** content authors create a class row
- **THEN** they can configure its ID and name, attack multipliers keyed by target class ID, and defense multipliers keyed by attacking class ID

#### Scenario: Both class matchup multipliers are present
- **WHEN** a matchup has values in both the attacking class's `AttackMultiply` and the defending class's `DefenseMultiply`
- **THEN** the data contract identifies the attacking class's `AttackMultiply` value as the preferred value

### Requirement: Skill data is represented by a DataTable row
The project SHALL provide a DataTable-compatible skill row containing `SkillId` (`int32`), `Name` (`FText`), and `EffectId` (`TArray<int32>`).

#### Scenario: Skill row references an effect group
- **WHEN** content authors create a skill row
- **THEN** they can configure its ID, name, and an ordered list of effect IDs belonging to that skill's effect group

### Requirement: Effect data is represented by a DataTable row
The project SHALL provide a DataTable-compatible effect row containing `EffectId` (`int32`), `Type` (`EEffectType`), and `Params` (`TArray<FString>`).

#### Scenario: Effect row stores type parameters
- **WHEN** content authors create an effect row
- **THEN** they can configure its ID, effect type, and an ordered list of string parameters

### Requirement: Effect type has an initial placeholder value
The project SHALL define `EEffectType` with `None` as its only value until concrete effect types are introduced.

#### Scenario: Placeholder effect type is available
- **WHEN** an effect row is authored before concrete effect types are defined
- **THEN** its type can be set to `None`
