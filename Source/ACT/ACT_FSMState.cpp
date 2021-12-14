// Fill out your copyright notice in the Description page of Project Settings.


#include "ACT_FSMState.h"

void UACT_FSMState::Init_FSMStateInfo(uint32 _KeyID, float _InputTime, int32 _StateID, int32 _MaxStateID)
{
	KeyID = _KeyID;
	InputTime = _InputTime;
	StateID = _StateID;
	MaxStateID = _MaxStateID;
}
void UACT_FSMState::Init_FSMStateInfo(FKey _Keycode, float _InputTime, int32 _StateID, int32 _MaxStateID)
{
	KeyID = GetTypeHash(_Keycode.GetFName());
	InputTime = _InputTime;
	StateID = _StateID;
	MaxStateID = _MaxStateID;
}

