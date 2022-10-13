// Fill out your copyright notice in the Description page of Project Settings.


#include "Paddle.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
APaddle::APaddle()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//Permite crear un objeto del tipo SM_Paddle
	SM_Paddle = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SM Paddle"));//SM_Paddle nombre del objeto para que se pueda identificar
	RootComponent = SM_Paddle;//Raiz

	SM_Paddle->SetEnableGravity(false);//Para que no tenga gravedad
	SM_Paddle->SetConstraintMode(EDOFMode::XZPlane);//PAra que trabeje en el plano XZ
	SM_Paddle->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);//Va a controlar la collisones fisicas y de lugar(programable)
	SM_Paddle->SetCollisionProfileName(TEXT("PhisycActor"));//Nombre para esa collision

	FloatingMovement = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("Flaoting pow movement"));

}

// Called when the game starts or when spawned
void APaddle::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APaddle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APaddle::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void APaddle::Move(float _AxisValue)
{
	//LLamando al metodo addmovementimput
	/*Crea un vector con el valor que va a recoger del eje x, va a crear un vector y le va aplicar moviento
	al objeto de entrada(Pawn objeto de entrada)
	*/
	AddMovementInput(FVector(_AxisValue, 0.0f, 0.0f), 1.0f, false);
}

