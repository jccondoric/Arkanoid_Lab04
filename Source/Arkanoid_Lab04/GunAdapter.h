// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SlingShot.h"
#include "GunAdapter.generated.h"
class AGun;
UCLASS()
class ARKANOID_LAB04_API AGunAdapter : public AActor,public 
ISlingShot
{
	GENERATED_BODY()
	
public:	
	 
	AGunAdapter();
private:
//The Weapon Actor
UPROPERTY();
AGun* Weapon;
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	// Fire the Weapon
		void Sling() override;


};
