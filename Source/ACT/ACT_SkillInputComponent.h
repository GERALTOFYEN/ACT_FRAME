// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ACT_SkillItem.h"
#include "ACT_FSMMachine.h"
#include "ACT_SkillInputComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent),Blueprintable )
class ACT_API UACT_SkillInputComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UACT_SkillInputComponent();
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
		TMap<UACT_SkillItem*, UACT_FSMMachine*> Skillmap;
	UPROPERTY(BlueprintReadOnly)
		AACTCharacter* Ownercharacter;
protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	UFUNCTION()
		void ConstructSkillsFSM();
	UFUNCTION()
		bool ConstructSkillsFSM1(UACT_SkillItem* SkillItem);


		
};
