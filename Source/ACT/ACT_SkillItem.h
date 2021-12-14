// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ACT_Item.h"
#include"ACT_Type.h"
#include "ACT_SkillItem.generated.h"



class AACTCharacter;
class AACT_Skill;
/**
 * 
 */
UCLASS()
class ACT_API UACT_SkillItem : public UACT_Item
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
		FName SkillNmae;
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
		TArray<FACT_InputStruct> inputskill;
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
		bool active = true;
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
		int32 skillpriority = 0;
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
		TSubclassOf<AACTCharacter> owner;
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
		TSubclassOf<AACT_Skill> skill;
};
