// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ACT_FSMState.h"
#include "TimerManager.h"
#include "ACT_FSMMachine.generated.h"

/**
 * 
 */
UCLASS()
class ACT_API UACT_FSMMachine : public UObject
{
	GENERATED_BODY()
public:
	UPROPERTY()
		TMap<int32, UACT_FSMState*> FSMStateMap;
	UPROPERTY()
		UACT_FSMState* CurrentState;
	UPROPERTY()
		bool Okay = false;
	FTimerHandle ResetTimer;
public:

	bool AddState(UACT_FSMState* StatetoAdd);
	bool ChangeState(int32 _StateID);
	void SetTimer(float TimeDelay);
	void Reset();
	void Check(int32 InputHash);
};
