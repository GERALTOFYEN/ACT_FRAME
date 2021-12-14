// Fill out your copyright notice in the Description page of Project Settings.


#include "ACT_AssetManager.h"
const FPrimaryAssetType UACT_AssetManager::Skilltype = TEXT("Skilltype");
const FPrimaryAssetType UACT_AssetManager::Motiontype = TEXT("Motiontype");
UACT_AssetManager& UACT_AssetManager::Get()
{
	UACT_AssetManager* Singleton = Cast<UACT_AssetManager>(GEngine->AssetManager);

	if (Singleton)
	{
		return *Singleton;
	}
	else
	{
		//UE_LOG(LogAssetManager, Fatal, TEXT("Cannot use AssetManager if no AssetManagerClassName is defined!"));
		return *NewObject<UACT_AssetManager>(); // never calls this
	}
}
