// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ACT_Type.h"
#include "ACT_Component.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent),Blueprintable)
class ACT_API UACT_Component : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UACT_Component();
	UPROPERTY(BlueprintReadWrite, EditAnywhere,Category="Properties")
		TMap <EACT_PropertyName, FACT_PropertyValue> Properties;
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	UFUNCTION(BlueprintPure)
		FORCEINLINE FACT_PropertyValue& GetPropertyStructByName(EACT_PropertyName name) { return *Properties.Find(name); }
	UFUNCTION(BlueprintPure)
		FORCEINLINE float GetPropertyValueByName(EACT_PropertyName name) { return Properties.Find(name)->current; }
	UFUNCTION(BlueprintCallable)
		bool SetPropertyValue(EACT_PropertyName name, float ByValue, bool updateUI);
	UFUNCTION(BlueprintCallable)
		bool ModifyPropertyValue(EACT_PropertyName name, float NewValue, bool updateUI);
	UFUNCTION()
		virtual void UpdatePropertyUI(EACT_PropertyName name);
	UFUNCTION(BlueprintImplementableEvent)
        void BP_UpdatePropertyUI(EACT_PropertyName name);
public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	
		
};
