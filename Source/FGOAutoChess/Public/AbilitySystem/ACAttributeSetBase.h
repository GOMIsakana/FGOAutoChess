// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "GameplayTagContainer.h"
#include "ACAttributeSetBase.generated.h"

UCLASS(Abstract)
class FGOAUTOCHESS_API UACAttributeSetBase : public UAttributeSet
{
	GENERATED_BODY()

public:
	UACAttributeSetBase();

	virtual int32 GetAttributeId(const FGameplayAttribute& Attribute) const;

	static FGameplayTag GetAttributeTag(FName AttributeName);
};

#define UAC_ATTRIBUTE_ACCESSORS(ClassName, PropertyName, IdValue) \
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName) \
	static FGameplayTag Get##PropertyName##AttributeTag() \
	{ \
		return UACAttributeSetBase::GetAttributeTag(GET_MEMBER_NAME_CHECKED(ClassName, PropertyName)); \
	} \
	static int32 Get##PropertyName##AttributeId() \
	{ \
		return IdValue; \
	}
