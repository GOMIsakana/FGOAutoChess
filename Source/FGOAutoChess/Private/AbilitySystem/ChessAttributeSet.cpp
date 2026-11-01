// Copyright Epic Games, Inc. All Rights Reserved.

#include "AbilitySystem/ChessAttributeSet.h"

#include "Net/UnrealNetwork.h"

int32 UChessAttributeSet::GetAttributeId(const FGameplayAttribute& Attribute) const
{
	if (Attribute == GetMaxHealthAttribute())
	{
		return GetMaxHealthAttributeId();
	}
	if (Attribute == GetHealthAttribute())
	{
		return GetHealthAttributeId();
	}
	if (Attribute == GetAttackAttribute())
	{
		return GetAttackAttributeId();
	}
	if (Attribute == GetShieldAttribute())
	{
		return GetShieldAttributeId();
	}
	if (Attribute == GetSpeedAttribute())
	{
		return GetSpeedAttributeId();
	}
	return Super::GetAttributeId(Attribute);
}

void UChessAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION_NOTIFY(UChessAttributeSet, MaxHealth, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UChessAttributeSet, Health, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UChessAttributeSet, Attack, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UChessAttributeSet, Shield, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UChessAttributeSet, Speed, COND_None, REPNOTIFY_Always);
}

void UChessAttributeSet::OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UChessAttributeSet, MaxHealth, OldMaxHealth);
}

void UChessAttributeSet::OnRep_Health(const FGameplayAttributeData& OldHealth)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UChessAttributeSet, Health, OldHealth);
}

void UChessAttributeSet::OnRep_Attack(const FGameplayAttributeData& OldAttack)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UChessAttributeSet, Attack, OldAttack);
}

void UChessAttributeSet::OnRep_Shield(const FGameplayAttributeData& OldShield)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UChessAttributeSet, Shield, OldShield);
}

void UChessAttributeSet::OnRep_Speed(const FGameplayAttributeData& OldSpeed)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UChessAttributeSet, Speed, OldSpeed);
}
