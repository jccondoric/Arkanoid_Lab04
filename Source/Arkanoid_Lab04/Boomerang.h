// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Boomerang.generated.h"

UCLASS()
class ARKANOID_LAB04_API ABoomerang : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABoomerang();
	virtual void Lanzar();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		class UStaticMeshComponent* SM_Boomerang;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		class UBoxComponent* BoomerangCollision;

public:	
	// Called every frame
	int direccion;
	virtual void Tick(float DeltaTime) override;

	void Regresar();

};
