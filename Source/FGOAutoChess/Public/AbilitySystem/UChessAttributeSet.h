// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "AttributeSet.h"
#include "UChessAttributeSet.generated.h"

#define UCHESS_ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

UCLASS()
class FGOAUTOCHESS_API UChessAttributeSet : public UAttributeSet
{
	GENERATED_BODY()

public:
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

protected:
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxHealth, Category = "Attributes")
	FGameplayAttributeData MaxHealth;
	UCHESS_ATTRIBUTE_ACCESSORS(UChessAttributeSet, MaxHealth)

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Health, Category = "Attributes")
	FGameplayAttributeData Health;
	UCHESS_ATTRIBUTE_ACCESSORS(UChessAttributeSet, Health)

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Attack, Category = "Attributes")
	FGameplayAttributeData Attack;
	UCHESS_ATTRIBUTE_ACCESSORS(UChessAttributeSet, Attack)

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Shield, Category = "Attributes")
	FGameplayAttributeData Shield;
	UCHESS_ATTRIBUTE_ACCESSORS(UChessAttributeSet, Shield)

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Speed, Category = "Attributes")
	FGameplayAttributeData Speed;
	UCHESS_ATTRIBUTE_ACCESSORS(UChessAttributeSet, Speed)

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

#undef UCHESS_ATTRIBUTE_ACCESSORS
