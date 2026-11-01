// Copyright Epic Games, Inc. All Rights Reserved.

#include "AbilitySystem/ACAttributeSetBase.h"

#include "GameplayTagsManager.h"

UACAttributeSetBase::UACAttributeSetBase()
{
	UGameplayTagsManager& GameplayTagsManager = UGameplayTagsManager::Get();
	for (TFieldIterator<FProperty> PropertyIt(GetClass()); PropertyIt; ++PropertyIt)
	{
		const FStructProperty* StructProperty = CastField<FStructProperty>(*PropertyIt);
		if (!StructProperty || StructProperty->Struct != FGameplayAttributeData::StaticStruct())
		{
			continue;
		}

		const FName TagName(*FString::Printf(TEXT("Attributes.%s"), *PropertyIt->GetName()));
		if (!GameplayTagsManager.RequestGameplayTag(TagName, false).IsValid())
		{
			GameplayTagsManager.AddNativeGameplayTag(TagName, FString::Printf(TEXT("Attribute %s"), *PropertyIt->GetName()));
		}
	}
}

int32 UACAttributeSetBase::GetAttributeId(const FGameplayAttribute& Attribute) const
{
	return INDEX_NONE;
}

FGameplayTag UACAttributeSetBase::GetAttributeTag(FName AttributeName)
{
	const FName TagName(*FString::Printf(TEXT("Attributes.%s"), *AttributeName.ToString()));
	return UGameplayTagsManager::Get().RequestGameplayTag(TagName, false);
}
