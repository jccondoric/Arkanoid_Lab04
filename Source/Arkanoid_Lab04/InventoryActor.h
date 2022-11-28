// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "InventoryActor.generated.h"

/**
 * 
 */
UCLASS()
class ARKANOID_LAB04_API AInventoryActor : public AStaticMeshActor
{
	GENERATED_BODY()
public:
	AInventoryActor();
protected:
	virtual void BeginPlay() override;
public:
	virtual void Tick(float DeltaTime) override;

	virtual void PickUp();
	virtual void PutDown(FTransform TargetLocation);


 }; 