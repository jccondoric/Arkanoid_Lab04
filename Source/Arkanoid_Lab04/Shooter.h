// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SlingShot.h"	
#include "Shooter.generated.h"

UCLASS()
class ARKANOID_LAB04_API AShooter : public AActor,public ISlingShot
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AShooter();

private:
	//The Weapon of the Shooter, that must be a SlingShot
	ISlingShot* SlingShot;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void SetSlingShot(AActor* SlingShotObj);

	void Sling();

};
