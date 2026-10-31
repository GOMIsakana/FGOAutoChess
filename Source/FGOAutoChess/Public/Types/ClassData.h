// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "ClassData.generated.h"

USTRUCT(BlueprintType)
struct FGOAUTOCHESS_API FClassData : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Class")
	int32 ClassId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Class")
	FText Name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Class")
	TMap<int32, float> AttackMultiply;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Class")
	TMap<int32, float> DefenseMultiply;
};
