// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AbilitySystem/Types/AttributeRegisterInfo.h"
#include "AttributeRegisterSubsystem.generated.h"

UCLASS()
class FGOAUTOCHESS_API UAttributeRegisterSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	UFUNCTION(BlueprintPure, BlueprintCallable, Category = "Attribute")
	FAttributeRegisterInfo GetAttributeInfoById(int32 Id) const;

	UFUNCTION(BlueprintPure, BlueprintCallable, Category = "Attribute")
	FAttributeRegisterInfo GetAttributeInfoByAttribute(const FGameplayAttribute& Attribute) const;

	UFUNCTION(BlueprintPure, BlueprintCallable, Category = "Attribute")
	FAttributeRegisterInfo GetAttributeInfoByTag(FGameplayTag Tag) const;

private:
	FAttributeRegisterInfo GetAttributeInfoByIndex(int32 Index) const;

	UPROPERTY(Transient)
	TArray<FAttributeRegisterInfo> AttributeInfo;

	TMap<int32, int32> IdToIndex;
	TMap<FGameplayAttribute, int32> AttributeToIndex;
	TMap<FGameplayTag, int32> TagToIndex;
};
