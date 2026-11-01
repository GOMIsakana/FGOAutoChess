# Spec Delta

## Purpose

Provides a stable, project-wide registry for Gameplay Ability System attributes so editor tooling and runtime gameplay can identify the same attribute by its fixed ID, reflected attribute, or GameplayTag.

## ADDED Requirements

### Requirement: Attributes are explicitly registered with stable IDs
The project SHALL allow each registered attribute to declare an explicit fixed ID independent of its registration order or array position.

#### Scenario: Chess attributes use their reserved ID range
- **WHEN** Chess attributes are registered
- **THEN** each uses a unique ID in the range 1000 through 1999

#### Scenario: Future AttributeSets use separate ID ranges
- **WHEN** attributes are registered for another AttributeSet such as Projectile
- **THEN** they use that AttributeSet's assigned non-overlapping ID range, with Projectile assigned 2000 through 2999

### Requirement: Registered attributes receive matching GameplayTags
The project SHALL register a native GameplayTag in the form `Attributes.XXX` for each registered attribute, where `XXX` is the attribute property's name, and repeated AttributeSet construction SHALL NOT register the same Tag more than once.

#### Scenario: GameplayTag matches the attribute name
- **WHEN** an attribute named `MaxHealth` is registered
- **THEN** the registry includes its matching GameplayTag `Attributes.MaxHealth`

#### Scenario: AttributeSet construction repeats
- **WHEN** an AttributeSet class default object and later instances are constructed
- **THEN** its attribute Tags remain registered once without duplicate-registration errors

### Requirement: Editor settings expose the generated attribute registry
The editor SHALL expose a configurable set of AttributeSet classes and a `bImportAttribute` trigger, and store imported registration records in a read-only `AttributeInfo` list in the `FGOAutoChess | Attribute` settings category.

#### Scenario: Import selected AttributeSets
- **WHEN** the user changes `bImportAttribute` in the editor
- **THEN** the settings import attributes from every selected AttributeSet class into `AttributeInfo` and save the generated records to config

#### Scenario: Reimport replaces generated records
- **WHEN** the user changes `bImportAttribute` again after an import
- **THEN** the generated `AttributeInfo` list is rebuilt from the currently selected classes without accumulating records from earlier imports

#### Scenario: Settings show imported attributes
- **WHEN** the attribute settings are displayed in the editor
- **THEN** `AttributeInfo` lists the imported IDs, attributes, and tags and cannot be edited by the user

### Requirement: Runtime attribute registry supports lookup by each key
At runtime, the attribute registry SHALL provide lookup by fixed ID, Gameplay Attribute, and GameplayTag, returning the complete registration record for a match.

#### Scenario: Lookup by fixed ID
- **WHEN** runtime code queries a registered ID
- **THEN** it receives the full record for that ID regardless of the record's array position

#### Scenario: Lookup by Gameplay Attribute or GameplayTag
- **WHEN** runtime code queries a registered Gameplay Attribute or GameplayTag
- **THEN** it receives the full record associated with that key

#### Scenario: Lookup key is not registered
- **WHEN** runtime code queries an unknown ID, Gameplay Attribute, or GameplayTag
- **THEN** the registry reports an ensure diagnostic identifying the failed key and returns an empty registration record

### Requirement: Duplicate registration is rejected with diagnostics
The import SHALL detect duplicate IDs, Gameplay Attributes, or GameplayTags, log an error identifying the conflict, and ignore the later conflicting record using deterministic class/property ordering.

#### Scenario: Imported records conflict
- **WHEN** imported classes contain duplicate IDs, Gameplay Attributes, or GameplayTags
- **THEN** an error is logged with the conflicting source details and the first record in deterministic import order remains while later conflicts are ignored
