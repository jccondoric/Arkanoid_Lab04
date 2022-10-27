// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Arkanoid_Lab04GameModeBase.generated.h"

/**
 * 
 */
class ABrick;

UCLASS()
class ARKANOID_LAB04_API AArkanoid_Lab04GameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;

	ABrick* ladrillo;

	
};
