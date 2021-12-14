// Fill out your copyright notice in the Description page of Project Settings.


#include "ACT_Component.h"

// Sets default values for this component's properties
UACT_Component::UACT_Component()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UACT_Component::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


bool UACT_Component::SetPropertyValue(EACT_PropertyName name, float NewValue, bool updateUI)
{
	if (Properties.Contains(name)) {
		FACT_PropertyValue Currentvalue = GetPropertyStructByName(name);
		Currentvalue.current = FMath::Clamp(NewValue,Currentvalue.min,Currentvalue.max);
		Properties.Add(name,Currentvalue);
		if (updateUI) UpdatePropertyUI(name);
	}
	return false;
}

bool UACT_Component::ModifyPropertyValue(EACT_PropertyName name, float ByValue, bool updateUI)
{
	if (ByValue != 0) {
		float OldValue = GetPropertyValueByName(name);
		return SetPropertyValue(name, OldValue + ByValue, updateUI);
	}
	return true;
}

void UACT_Component::UpdatePropertyUI(EACT_PropertyName name)
{
	BP_UpdatePropertyUI(name);
}

// Called every frame
void UACT_Component::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}
