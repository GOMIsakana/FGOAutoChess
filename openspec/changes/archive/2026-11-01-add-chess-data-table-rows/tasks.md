# Tasks

## 1. Define split reflected DataTable rows

- [x] 1.1 Add `FChessData`, `FClassData`, and `FSkillData` as editable `FTableRowBase` structs in separate headers under `Public/Types/`; verify their fields match `specs/chess-data-tables/spec.md`.
- [x] 1.2 Add `FEffectData` and its `EEffectType` placeholder enum in `Public/Types/EffectData.h`, with `None` as the only value; verify its reflected fields match the spec.

## 2. Verify Unreal integration

- [x] 2.1 Build the `FGOAutoChess` runtime module and confirm Unreal Header Tool accepts all four declarations as DataTable row types.
