// Copyright Epic Games, Inc. All Rights Reserved.

#include "Subsystem/GameInstance/AttributeRegisterSubsystem.h"

#include "Settings/AttributeSettings.h"

void UAttributeRegisterSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	const UAttributeSettings* Settings = GetDefault<UAttributeSettings>();
	AttributeInfo = Settings->AttributeInfo;
	IdToIndex.Reset();
	AttributeToIndex.Reset();
	TagToIndex.Reset();

	for (int32 Index = 0; Index < AttributeInfo.Num(); ++Index)
	{
		const FAttributeRegisterInfo& Info = AttributeInfo[Index];
		IdToIndex.Add(Info.Id, Index);
		AttributeToIndex.Add(Info.Attribute, Index);
		TagToIndex.Add(Info.Tag, Index);
	}
}

void UAttributeRegisterSubsystem::Deinitialize()
{
	AttributeInfo.Reset();
	IdToIndex.Reset();
	AttributeToIndex.Reset();
	TagToIndex.Reset();

	Super::Deinitialize();
}

FAttributeRegisterInfo UAttributeRegisterSubsystem::GetAttributeInfoById(int32 Id) const
{
	const int32* Index = IdToIndex.Find(Id);
	if (!ensureMsgf(Index, TEXT("No attribute registration found for ID %d."), Id))
	{
		return FAttributeRegisterInfo();
	}
	return GetAttributeInfoByIndex(*Index);
}

FAttributeRegisterInfo UAttributeRegisterSubsystem::GetAttributeInfoByAttribute(const FGameplayAttribute& Attribute) const
{
	const int32* Index = AttributeToIndex.Find(Attribute);
	if (!ensureMsgf(Index, TEXT("No attribute registration found for GameplayAttribute '%s'."), *Attribute.GetName()))
	{
		return FAttributeRegisterInfo();
	}
	return GetAttributeInfoByIndex(*Index);
}

FAttributeRegisterInfo UAttributeRegisterSubsystem::GetAttributeInfoByTag(FGameplayTag Tag) const
{
	const int32* Index = TagToIndex.Find(Tag);
	if (!ensureMsgf(Index, TEXT("No attribute registration found for GameplayTag '%s'."), *Tag.ToString()))
	{
		return FAttributeRegisterInfo();
	}
	return GetAttributeInfoByIndex(*Index);
}

FAttributeRegisterInfo UAttributeRegisterSubsystem::GetAttributeInfoByIndex(int32 Index) const
{
	if (!ensureMsgf(AttributeInfo.IsValidIndex(Index), TEXT("Attribute registry index %d is invalid."), Index))
	{
		return FAttributeRegisterInfo();
	}
	return AttributeInfo[Index];
}
