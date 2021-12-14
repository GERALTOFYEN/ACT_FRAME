// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/AssetManager.h"
#include "ACT_AssetManager.generated.h"

/**
 * 
 */
UCLASS()
class ACT_API UACT_AssetManager : public UAssetManager
{
public:
	GENERATED_BODY()
		static const FPrimaryAssetType Skilltype;
	    static const FPrimaryAssetType Motiontype;

		/** Returns the current AssetManager object */
		static UACT_AssetManager& Get();
};
