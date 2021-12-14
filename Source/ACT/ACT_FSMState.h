// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "InputCoreTypes.h"
#include "ACT_FSMState.generated.h"


/**
 * 
 */
UCLASS()
class ACT_API UACT_FSMState : public UObject
{
	 //uint32 GetTypeHash(const FKey& Key) { return GetTypeHash(Key.KeyName);
public:
	GENERATED_BODY()
	uint32 KeyID;
	float InputTime;
	int32 StateID;
	int32 MaxStateID;
	void Init_FSMStateInfo(uint32 _KeyID, float _InputTime, int32 _StateID, int32 _MaxStateID);
	void Init_FSMStateInfo(FKey _Keycode, float _InputTime, int32 _StateID, int32 _MaxStateID);
};