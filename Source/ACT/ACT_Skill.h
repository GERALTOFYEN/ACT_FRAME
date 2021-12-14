// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ACTCharacter.h"
#include "ACT_SkillItem.h"
#include "ACT_Skill.generated.h"

UCLASS()
class ACT_API AACT_Skill : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AACT_Skill();
	UFUNCTION(BlueprintCallable)
		void Perform(AACTCharacter* Skillowner, UACT_SkillItem* SkillDataAsset);
	UFUNCTION(BlueprintImplementableEvent)
		void BP_SkillProcess(AACTCharacter* Skillowner, UACT_SkillItem* SkillDataAsset);
	UFUNCTION()
		virtual void SkillProcess(AACTCharacter* Skillowner, UACT_SkillItem* SkillDataAsset);
};
