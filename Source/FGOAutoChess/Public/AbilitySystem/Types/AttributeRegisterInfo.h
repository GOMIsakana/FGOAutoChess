// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "GameplayTagContainer.h"
#include "AttributeRegisterInfo.generated.h"

USTRUCT(BlueprintType)
struct FGOAUTOCHESS_API FAttributeRegisterInfo
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Attribute")
	int32 Id = INDEX_NONE;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Attribute")
	FGameplayAttribute Attribute;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Attribute")
	FGameplayTag Tag;

	bool IsValid() const
	{
		return Id != INDEX_NONE && Attribute.IsValid() && Tag.IsValid();
	}
};
