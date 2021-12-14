// Fill out your copyright notice in the Description page of Project Settings.


#include "ACT_SkillInputComponent.h"
#include "ACT/ACT_AssetManager.h"
// Sets default values for this component's properties
UACT_SkillInputComponent::UACT_SkillInputComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UACT_SkillInputComponent::BeginPlay()
{
	Super::BeginPlay();
	ConstructSkillsFSM();
	// ...
	
}

void UACT_SkillInputComponent::ConstructSkillsFSM()
{
	UACT_AssetManager &manager = UACT_AssetManager::Get();
	TArray<FPrimaryAssetId> SkillID;
	manager.GetPrimaryAssetIdList(manager.Skilltype, SkillID);
	for (auto _id : SkillID)
	{
		UACT_SkillItem*TempItem = manager.GetPrimaryAssetObject<UACT_SkillItem>(_id);
		if (TempItem->owner)
		{
			ConstructSkillsFSM1(TempItem);
		}
	}

}

bool UACT_SkillInputComponent::ConstructSkillsFSM1(UACT_SkillItem* SkillItem)
{
	if (SkillItem&& SkillItem->inputskill.Num()>0)
	{
		UACT_FSMMachine* currentFSM = NewObject<UACT_FSMMachine>(this);
		if (currentFSM)
		{
			for (int i = 0;i<SkillItem->inputskill.Num();i++)
			{
				UACT_FSMState * NewState = NewObject<UACT_FSMState>(currentFSM);
				NewState->Init_FSMStateInfo(SkillItem->inputskill[i].key, SkillItem->inputskill[i].InputTime, i, SkillItem->inputskill.Num() - 1);
				currentFSM->AddState(NewState);
			}
			Skillmap.Add(SkillItem, currentFSM);
			return true;
		}
		else return false;
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Red, TEXT("skill system find illegal skill input"));
		return false;
	}
}

