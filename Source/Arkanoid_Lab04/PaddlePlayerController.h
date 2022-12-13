// Fill out your copyright notice in the Description page of Project Settings.
//Es el controlador de la reproduccion del videojuego(cuando empieza,como empieza)
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "PaddlePlayerController.generated.h"

/**
 * 
 */
class ABall;
UCLASS()
class ARKANOID_LAB04_API APaddlePlayerController : public APlayerController
{
	GENERATED_BODY()

		APaddlePlayerController();

	UFUNCTION()//sin parametros
		//virtual para que mi clase hija tenga un mismo metodo(este metodo no hace lo mismo POLIMORFISMO)
		virtual void SetupInputComponent() override;

protected :
	virtual void BeginPlay() override;
	void Move(float _AxisValue);
	void MoveVer(float _VerAxisValue);

	void Lanch();
	

	
	UPROPERTY(EditAnywhere)
		TSubclassOf<ABall> BallObj;

	ABall* MyBall;
	FVector SpawnLocation = FVector(10.0f, 0.0f, 40.0f);
	FRotator SpawnRotator = FRotator(0.0f, 0.0f, 0.0f);

	FActorSpawnParameters SpawnInfo;

	

public:
	void SpawnNewBall();

};