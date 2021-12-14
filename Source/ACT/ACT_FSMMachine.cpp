// Fill out your copyright notice in the Description page of Project Settings.


#include "ACT_FSMMachine.h"

bool UACT_FSMMachine::AddState(UACT_FSMState* StatetoAdd)
{
	if (StatetoAdd && !FSMStateMap.Contains(StatetoAdd->StateID)) {
		FSMStateMap.Add(StatetoAdd->StateID, StatetoAdd);
		return true;
	}return false;
}

bool UACT_FSMMachine::ChangeState(int32 _StateID)
{
	if (FSMStateMap.Contains(_StateID)) {
		UACT_FSMState * _state = FSMStateMap[_StateID];
		if (_state) {
			CurrentState = _state;
		}
		return false;
	}return false;
}

void UACT_FSMMachine::SetTimer(float TimeDelay)//Timer在world的类下面
{
	if (GetWorld()) {
		GetWorld()->GetTimerManager().SetTimer(ResetTimer, this, &UACT_FSMMachine::Reset, TimeDelay + 0.001f, false);
	}
}
void UACT_FSMMachine::Reset() 
{
	if (GetWorld()) {
		Okay = false;
		GetWorld()->GetTimerManager().ClearTimer(ResetTimer);
		ChangeState(0);
	}
}
void UACT_FSMMachine::Check(int32 InputHash) 
{
	if (CurrentState == nullptr && FSMStateMap[0]) Reset();
	if (CurrentState && InputHash == CurrentState->KeyID) {
		SetTimer(CurrentState->InputTime);
		if (CurrentState->KeyID == CurrentState->MaxStateID) {
			Okay = true;
			ChangeState(0);
			return;
		}
		else ChangeState(CurrentState->StateID + 1);
	}
	else Reset();

}
