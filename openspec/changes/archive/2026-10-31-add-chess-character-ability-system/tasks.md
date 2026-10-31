# Tasks

## 1. Configure Gameplay Ability System dependency

- [x] 1.1 Confirm the Gameplay Ability System plugin is enabled for the project and add the required `GameplayAbilities`, `GameplayTags`, and `GameplayTasks` dependencies to `FGOAutoChess.Build.cs`; verify the module rule contains the dependencies and the project descriptor enables the plugin if needed.

## 2. Add project base classes

- [x] 2.1 Add `AACChess` header and implementation under `Public/Character/` and `Private/Character/`, deriving from `ACharacter` and supporting Blueprint subclassing; verify the reflected class and expected source paths.
- [x] 2.2 Add `UACAbilitySystemComponent` header and implementation under `Public/AbilitySystem/` and `Private/AbilitySystem/`, deriving from `UAbilitySystemComponent`; verify the reflected class and expected source paths.
- [x] 2.3 Make `AACChess` implement `IAbilitySystemInterface`, own a protected `UACAbilitySystemComponent` default subobject, and return it from `GetAbilitySystemComponent()`; verify both the interface and the returned component refer to the owned subobject.

## 3. Integration verification

- [x] 3.1 Compile the `FGOAutoChess` runtime module with UnrealBuildTool and confirm Unreal Header Tool accepts both classes and their base types.
