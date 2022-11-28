// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Brick.h"
#include "Arkanoid_Lab04GameModeBase.generated.h"



/**
 * 
 */
class ABrick;
;
UCLASS()
class ARKANOID_LAB04_API AArkanoid_Lab04GameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	AArkanoid_Lab04GameModeBase();

private:
	//The Shooter Actor that holds the Gun Adapter
	UPROPERTY()
		class AShooter* Shooter;


public:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	ABrick* ladrillo;

	
};
