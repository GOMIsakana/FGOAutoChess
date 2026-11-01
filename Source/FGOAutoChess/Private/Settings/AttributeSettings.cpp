// Copyright Epic Games, Inc. All Rights Reserved.

#include "Settings/AttributeSettings.h"

#include "AbilitySystem/ACAttributeSetBase.h"
#include "AbilitySystem/Types/AttributeRegisterInfo.h"
#include "AbilitySystem/ChessAttributeSet.h"
#include "GameplayTagsManager.h"
#include "UObject/UnrealType.h"

UAttributeSettings::UAttributeSettings()
{
	AttributeSetClasses.Add(UChessAttributeSet::StaticClass());
}

FText UAttributeSettings::GetSectionText() const
{
	return NSLOCTEXT("FGOAutoChess", "AttributeSettingsSection", "FGOAutoChess | Attribute");
}

#if WITH_EDITOR
void UAttributeSettings::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);

	if (PropertyChangedEvent.GetPropertyName() == GET_MEMBER_NAME_CHECKED(UAttributeSettings, bImportAttribute))
	{
		ImportAttributes();
	}
}

void UAttributeSettings::ImportAttributes()
{
	AttributeInfo.Reset();

	TArray<UClass*> SortedClasses;
	for (const TSubclassOf<UAttributeSet>& AttributeSetClass : AttributeSetClasses)
	{
		if (AttributeSetClass)
		{
			SortedClasses.Add(AttributeSetClass.Get());
		}
	}
	SortedClasses.Sort([](const UClass& Left, const UClass& Right)
	{
		return Left.GetPathName() < Right.GetPathName();
	});

	for (UClass* AttributeSetClass : SortedClasses)
	{
		const UACAttributeSetBase* AttributeSetCDO = Cast<UACAttributeSetBase>(AttributeSetClass->GetDefaultObject());
		if (!AttributeSetCDO)
		{
			UE_LOG(LogTemp, Error, TEXT("Attribute import skipped class %s because it does not derive from UACAttributeSetBase."), *AttributeSetClass->GetPathName());
			continue;
		}

		TArray<FGameplayAttribute> Attributes;
		UAttributeSet::GetAttributesFromSetClass(AttributeSetClass, Attributes);
		Attributes.Sort([](const FGameplayAttribute& Left, const FGameplayAttribute& Right)
		{
			return Left.GetName() < Right.GetName();
		});

		for (const FGameplayAttribute& Attribute : Attributes)
		{
			const int32 Id = AttributeSetCDO->GetAttributeId(Attribute);
			const FGameplayTag Tag = UACAttributeSetBase::GetAttributeTag(FName(*Attribute.GetName()));
			const FString Source = FString::Printf(TEXT("%s.%s"), *AttributeSetClass->GetName(), *Attribute.GetName());

			if (Id == INDEX_NONE || !Attribute.IsValid() || !Tag.IsValid())
			{
				UE_LOG(LogTemp, Error, TEXT("Attribute import skipped invalid registration %s (ID %d, Tag %s)."), *Source, Id, *Tag.ToString());
				continue;
			}

			const FAttributeRegisterInfo* Conflict = AttributeInfo.FindByPredicate([&](const FAttributeRegisterInfo& Existing)
			{
				return Existing.Id == Id || Existing.Attribute == Attribute || Existing.Tag == Tag;
			});
			if (Conflict)
			{
				UE_LOG(LogTemp, Error, TEXT("Attribute import conflict for %s (ID %d, Tag %s); existing registration %s wins."),
					*Source, Id, *Tag.ToString(), *Conflict->Attribute.GetName());
				continue;
			}

			FAttributeRegisterInfo& NewInfo = AttributeInfo.AddDefaulted_GetRef();
			NewInfo.Id = Id;
			NewInfo.Attribute = Attribute;
			NewInfo.Tag = Tag;
		}
	}

	SaveConfig();
}
#endif
