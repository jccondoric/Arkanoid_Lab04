// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Brick.h"
#include "IronBrick.generated.h"

/**
 * 
 */
UCLASS()
class ARKANOID_LAB04_API AIronBrick : public ABrick
{
	GENERATED_BODY()
public:
		AIronBrick();

		FString NameCapsule;
	
};
