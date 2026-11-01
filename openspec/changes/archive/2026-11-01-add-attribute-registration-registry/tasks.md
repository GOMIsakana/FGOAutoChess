# Tasks

## 1. Shared Attribute Registration Types

- [x] 1.1 Add `FAttributeRegisterInfo` with fixed ID, `FGameplayAttribute`, and `FGameplayTag`, plus the reusable `UACAttributeSetBase` convention, per-attribute static Tag/ID accessors, and a class-level attribute-to-ID mapping hook; verify reflected types compile and mapping calls return each fixed getter ID.
- [x] 1.2 Add idempotent native GameplayTag registration to the AttributeSet base construction path without modifying Settings data; verify repeated class/default/instance construction does not append records or log duplicate Tag errors.

## 2. Editor Settings and Attribute Definitions

- [x] 2.1 Add `UAttributeSettings` with a configurable `TSet<TSubclassOf<UAttributeSet>>`, `bImportAttribute` trigger, and read-only `AttributeInfo` list under `FGOAutoChess | Attribute`; add the DeveloperSettings dependency and verify only the class set and trigger are editable.
- [x] 2.2 Implement editor import on `bImportAttribute` changes using `UAttributeSet::GetAttributesFromSetClass()` and the selected class CDO's mapping hook; rebuild the generated list in stable class/attribute order, save it to config, and verify repeated imports do not accumulate stale records.
- [x] 2.3 Configure `UChessAttributeSet` for import with explicit IDs in 1000-1999; verify all five current attributes are imported with matching `Attributes.<PropertyName>` tags and duplicate conflicts log source details while keeping the first record.

## 3. Runtime Registry

- [x] 3.1 Add `UAttributeRegisterSubsystem` to copy the persisted settings list and build ID, `FGameplayAttribute`, and `FGameplayTag` maps to record indices; verify lookups return the correct complete records after initialization from saved settings.
- [x] 3.2 Implement lookup by ID, `FGameplayAttribute`, and `FGameplayTag`, including ensure diagnostics with the failed key and empty-record fallback; verify each unknown-key path reports its key and returns the default record.

## 4. Integration

- [x] 4.1 Replace the Chess attribute accessor declarations with the shared base convention and static Tag/ID accessors without changing replication behavior; verify the FGOAutoChess module builds and all five imported records remain queryable by each key type.
