// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "ACT_GameInstance.generated.h"

/**
 * 
 */
UCLASS()
class ACT_API UACT_GameInstance : public UGameInstance
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Autoload")
		TArray<FPrimaryAssetType> AutoLoadTypes;
	void AutoLoadData();
	virtual void Init() override;
};
