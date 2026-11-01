# Design

## Context

See proposal.md for motivation and `specs/gameplay-attribute-registry/spec.md` for required behavior. The module currently has a project-local accessor macro and a `UChessAttributeSet` with five reflected GAS attributes. GameplayTags and GameplayAbilities are already module dependencies; DeveloperSettings is not.

## Goals / Non-Goals

**Goals:**
- Provide convenient per-attribute static Tag and ID accessors while making selected AttributeSets importable from editor settings.
- Make import repeatable and ensure the saved settings list is the single source copied by runtime lookup.
- Support future project AttributeSets through a common base and assigned ID ranges.

**Non-Goals:**
- User-editing individual generated registration records.
- Defining gameplay rules, attribute defaults, or attribute replication behavior.
- Dynamically discovering arbitrary third-party AttributeSets that do not opt into the project registration mechanism.

## Decisions

- **Separate Tag declaration from registry import.** `UACAttributeSetBase` provides the shared attribute declaration/accessor convention and per-attribute static `Get<Property>AttributeTag()` and `Get<Property>AttributeId()` accessors. Its additional constructor behavior only registers the attribute Tag; it does not append records to `UAttributeSettings`. This prevents class construction from mutating the registry list.
- **Make constructor Tag registration idempotent.** AttributeSet constructors can run for class defaults, archetypes, and instances. Tag registration must check/register each native name idempotently so repeated object construction does not cause duplicate-tag errors.
- **Enumerate attributes with GAS and resolve IDs through a class-level mapping hook.** `UAttributeSettings` owns a configurable `TSet<TSubclassOf<UAttributeSet>>` and an editable `bImportAttribute` trigger. The importer calls `UAttributeSet::GetAttributesFromSetClass()` for each selected class to enumerate its `FGameplayAttribute` values, then calls a virtual class-level mapping function on that class's CDO to resolve each attribute to its fixed ID by invoking the per-attribute static ID getter. Tags are derived from the property name and use the same name as the static Tag getter. This keeps IDs in one source (the fixed getter literals) without requiring plain static functions to be exposed through UHT reflection.
- **Treat the import trigger as an editor action.** When `bImportAttribute` changes in the editor, import the currently selected class set. The import handler rebuilds `AttributeInfo` from scratch rather than appending, so repeated toggles cannot accumulate stale or duplicate generated entries. The generated list is saved to the settings config after import; the runtime subsystem does not repeat editor import work.
- **Make import order deterministic.** A `TSet` does not promise a stable iteration order. Sort selected classes by stable class path, then enumerate properties by stable property name before processing. This makes first-registration-wins duplicate handling consistent across runs.
- **Keep IDs explicit and separate from list positions.** Each attribute supplies a fixed ID. Chess uses 1000-1999 and the reserved Projectile range is 2000-2999. The generated `AttributeInfo` array order is not part of the ID contract.
- **Generate GameplayTags from property names.** Tags use `Attributes.XXX`, where `XXX` is the property name. The property name is the leaf, so names must be unique across selected AttributeSets; duplicate tags are diagnosed and the later sorted entry is ignored.
- **Use `UAttributeSettings` as the editor authority and `UAttributeRegisterSubsystem` as the runtime authority.** Settings presents the configured class set, import trigger, and read-only generated `AttributeInfo` under `FGOAutoChess | Attribute`. The subsystem copies the persisted generated list at initialization and builds three maps from ID, `FGameplayAttribute`, and `FGameplayTag` to array indices.
- **Reject duplicate registry keys deterministically.** During import, check IDs, attributes, and tags against already accepted records. On conflict, log the conflicting key and class/property, retain the earlier record, and ignore the later record. The expected registry is small, so linear checks are sufficient.
- **Diagnose failed runtime lookups.** Lookup functions report an ensure diagnostic containing the queried key when unresolved and return a default-constructed record. Callers must treat that record as invalid.

## Risks / Trade-offs

- Each AttributeSet's class-level ID mapping can omit an attribute or return a mismatched ID → implement the mapping by calling the corresponding static ID getters and return `INDEX_NONE` for unknown attributes, then rely on import validation to report missing or conflicting entries.
- Import-time settings serialization may not preserve a `FGameplayAttribute` identically across engine versions → verify editor save/reload and runtime load of generated records; if serialization is not reliable, store stable class/property references and reconstruct the attribute at runtime.
- Constructors execute repeatedly → make Tag registration idempotent and keep record import exclusively behind the settings trigger.
- A missed class in the configured set leaves its attributes unavailable → display the configured class set and validate imported attributes against the selected classes.
- Property-name-derived tags collide when selected sets share names → detect duplicate tags, report both source class/property pairs, and keep the first according to stable sorted import order.
- A fixed numeric ID becomes a compatibility contract once referenced by data or gameplay → never renumber an existing attribute; reserve non-overlapping ranges for new AttributeSets.
- `ensure` diagnostics are non-fatal in normal Unreal builds → return a default record and require callers to check validity when failure is recoverable.

## Migration Plan

1. Add the common AttributeSet base, registration record, DeveloperSettings class, and runtime subsystem.
2. Add a configurable selected class set and editor import trigger, then import the current Chess attributes with stable IDs in the Chess range.
3. Save and reload the generated settings data, then confirm runtime lookups resolve each key type.

Rollback consists of removing the registration infrastructure and restoring the previous attribute accessor declarations. Remove generated config fields or records as part of rollback if they were persisted; no gameplay data migration is expected.
