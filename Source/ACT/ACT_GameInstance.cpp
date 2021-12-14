// Fill out your copyright notice in the Description page of Project Settings.


#include "ACT_GameInstance.h"
#include "ACT_AssetManager.h"
void UACT_GameInstance::AutoLoadData()
{
	UACT_AssetManager &Manager = UACT_AssetManager::Get();
	for (auto&Type : AutoLoadTypes) {
		FPrimaryAssetType CurrentType = Type;
		TArray<FPrimaryAssetId> AssetId;
		if (Manager.GetPrimaryAssetIdList(CurrentType, AssetId)) {
			Manager.LoadPrimaryAssets(AssetId, TArray<FName>(),FStreamableDelegate(),0);
		}
	}
}
void UACT_GameInstance::Init()
{
	Super::Init();
	AutoLoadData();
}

