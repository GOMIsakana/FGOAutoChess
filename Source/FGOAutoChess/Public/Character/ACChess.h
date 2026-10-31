// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/Character.h"
#include "ACChess.generated.h"

class UACAbilitySystemComponent;

UCLASS(Blueprintable)
class FGOAUTOCHESS_API AACChess : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	AACChess();

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Abilities")
	TObjectPtr<UACAbilitySystemComponent> AbilitySystemComponent;
};
