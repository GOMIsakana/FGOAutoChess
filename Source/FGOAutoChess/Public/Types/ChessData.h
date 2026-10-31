// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "GameplayTagContainer.h"
#include "ChessData.generated.h"

USTRUCT(BlueprintType)
struct FGOAUTOCHESS_API FChessData : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Chess")
	int32 ChessId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Chess")
	FText Name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Chess")
	int32 ClassId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Chess")
	TMap<FGameplayTag, float> Attribute;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Chess")
	TArray<int32> PrimarySkill;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Chess")
	TArray<int32> PassiveSkill;
};
