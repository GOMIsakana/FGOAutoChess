// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "EffectData.generated.h"

UENUM(BlueprintType)
enum class EEffectType : uint8
{
	None UMETA(DisplayName = "None")
};

USTRUCT(BlueprintType)
struct FGOAUTOCHESS_API FEffectData : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Effect")
	int32 EffectId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Effect")
	EEffectType Type;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Effect")
	TArray<FString> Params;
};
