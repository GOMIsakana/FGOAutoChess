# Tasks

## 1. Implement the attribute set

- [x] 1.1 Add the public `UChessAttributeSet` header and private implementation under the AbilitySystem folders, deriving from `UAttributeSet`; verify the runtime module compiles with the class included.
- [x] 1.2 Declare MaxHealth, Health, Attack, Shield, and Speed as `FGameplayAttributeData` with standard GAS accessors and replication notifications; verify all five attributes are discoverable by GAS and replicated from server to client.
- [x] 1.3 Keep the class free of defaults and combat calculations; verify no initialization, clamping, damage handling, or other combat behavior is introduced.
