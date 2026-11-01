// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "AbilitySystem/ACAttributeSetBase.h"
#include "ChessAttributeSet.generated.h"

UCLASS()
class FGOAUTOCHESS_API UChessAttributeSet : public UACAttributeSetBase
{
	GENERATED_BODY()

public:
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	virtual int32 GetAttributeId(const FGameplayAttribute& Attribute) const override;

protected:
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxHealth, Category = "Attributes")
	FGameplayAttributeData MaxHealth;
	UAC_ATTRIBUTE_ACCESSORS(UChessAttributeSet, MaxHealth, 1000)

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Health, Category = "Attributes")
	FGameplayAttributeData Health;
	UAC_ATTRIBUTE_ACCESSORS(UChessAttributeSet, Health, 1001)

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Attack, Category = "Attributes")
	FGameplayAttributeData Attack;
	UAC_ATTRIBUTE_ACCESSORS(UChessAttributeSet, Attack, 1002)

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Shield, Category = "Attributes")
	FGameplayAttributeData Shield;
	UAC_ATTRIBUTE_ACCESSORS(UChessAttributeSet, Shield, 1003)

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Speed, Category = "Attributes")
	FGameplayAttributeData Speed;
	UAC_ATTRIBUTE_ACCESSORS(UChessAttributeSet, Speed, 1004)

	UFUNCTION()
	void OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth);

	UFUNCTION()
	void OnRep_Health(const FGameplayAttributeData& OldHealth);

	UFUNCTION()
	void OnRep_Attack(const FGameplayAttributeData& OldAttack);

	UFUNCTION()
	void OnRep_Shield(const FGameplayAttributeData& OldShield);

	UFUNCTION()
	void OnRep_Speed(const FGameplayAttributeData& OldSpeed);
};
