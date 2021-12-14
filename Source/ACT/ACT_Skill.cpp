// Fill out your copyright notice in the Description page of Project Settings.


#include "ACT_Skill.h"

// Sets default values
AACT_Skill::AACT_Skill()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void AACT_Skill::Perform(AACTCharacter* Skillowner, UACT_SkillItem* SkillDataAsset)
{
	SkillProcess(Skillowner, SkillDataAsset);
	BP_SkillProcess(Skillowner, SkillDataAsset);
}

void AACT_Skill::SkillProcess(AACTCharacter* owner, UACT_SkillItem* SkillDataAsset)
{

}




