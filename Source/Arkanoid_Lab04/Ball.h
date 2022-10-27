// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Ball.generated.h"


class UProjectileMovementComponent;

UCLASS()
class ARKANOID_LAB04_API ABall : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABall();
	
	virtual void Launch();
	bool BallLaunched;
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		UStaticMeshComponent* SM_Ball;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		UProjectileMovementComponent* ProjectileMovement;


public:	
	// Called every frame
	float AngleAxis;
	int direccion;
	virtual void Tick(float DeltaTime) override;
	 
	UFUNCTION()
		UStaticMeshComponent* GetBall();
///////////////////////////////////////////////////////////
//public:
//	UPROPERTY(EditAnywhere, Category = Movement)
//		float AngleAxis;
//
//	UPROPERTY(EditAnywhere, Category = Movement)
//		FVector Dimensions;
//
//	UPROPERTY(EditAnywhere, Category = Movement)
//		FVector AxisVector;
//
//	UPROPERTY(EditAnywhere, Category = Movement)
//		float Multiplier;



};
