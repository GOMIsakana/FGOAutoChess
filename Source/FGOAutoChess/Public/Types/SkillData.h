// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "SkillData.generated.h"

USTRUCT(BlueprintType)
struct FGOAUTOCHESS_API FSkillData : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Skill")
	int32 SkillId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Skill")
	FText Name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Skill")
	TArray<int32> EffectId;
};
