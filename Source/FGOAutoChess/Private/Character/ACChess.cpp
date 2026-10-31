// Copyright Epic Games, Inc. All Rights Reserved.

#include "Character/ACChess.h"

#include "AbilitySystem/ACAbilitySystemComponent.h"

AACChess::AACChess()
{
	AbilitySystemComponent = CreateDefaultSubobject<UACAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
}

UAbilitySystemComponent* AACChess::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}
