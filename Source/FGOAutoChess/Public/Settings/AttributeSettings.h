// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystem/Types/AttributeRegisterInfo.h"
#include "Engine/DeveloperSettings.h"
#include "AttributeSettings.generated.h"

class UAttributeSet;

UCLASS(Config = Game, DefaultConfig)
class FGOAUTOCHESS_API UAttributeSettings : public UDeveloperSettings
{
	GENERATED_BODY()

public:
	UAttributeSettings();

	virtual FName GetCategoryName() const override { return TEXT("Project"); }
	virtual FName GetSectionName() const override { return TEXT("Attribute"); }
	virtual FText GetSectionText() const override;

	UPROPERTY(Config, EditAnywhere, Category = "Attribute")
	TSet<TSubclassOf<UAttributeSet>> AttributeSetClasses;

	UPROPERTY(Config, EditAnywhere, Category = "Attribute")
	bool bImportAttribute = false;

	UPROPERTY(Config, VisibleAnywhere, Category = "Attribute")
	TArray<FAttributeRegisterInfo> AttributeInfo;

#if WITH_EDITOR
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
#endif

private:
#if WITH_EDITOR
	void ImportAttributes();
#endif
};
