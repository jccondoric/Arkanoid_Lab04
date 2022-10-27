// Fill out your copyright notice in the Description page of Project Settings.


#include "PaddlePlayerController.h"

#include "Kismet/GameplayStatics.h"
#include "Camera/CameraActor.h"

#include "NavMesh/NavMeshBoundsVolume.h"

#include "Paddle.h"
#include "Ball.h"


APaddlePlayerController::APaddlePlayerController()
{
}

void APaddlePlayerController::SetupInputComponent()
{

	Super::SetupInputComponent();

	EnableInput(this);

	InputComponent->BindAxis("Move", this, &APaddlePlayerController::Move);
	InputComponent->BindAxis("MoveVer", this, &APaddlePlayerController::MoveVer);

	InputComponent->BindAction("Launch", IE_Pressed, this, &APaddlePlayerController::Lanch);

}

void APaddlePlayerController::BeginPlay()
{
	//Creando un Array de Actores(Contenedor Avanzado)
	TArray<AActor*> CameraActors;

	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ACameraActor::StaticClass(), CameraActors);

	//Cual camara va ha ver
	FViewTargetTransitionParams Params;
	SetViewTarget(CameraActors[0], Params);

	SpawnNewBall();

}

void APaddlePlayerController::Move(float _AxisValue)
{

	auto MyPawn = Cast<APaddle>(GetPawn());  

	if (MyPawn) {
		MyPawn->Move(_AxisValue);//permitiendo implementar codigo para que se pueda mover el objeto a partir de player controller
	}


}

void APaddlePlayerController::MoveVer(float _VerAxisValue)
{

	auto MyPawn = Cast<APaddle>(GetPawn());

	if (MyPawn) {
		MyPawn->MoveVer(_VerAxisValue);//permitiendo implementar codigo para que se pueda mover el objeto a partir de player controller
	}

}

void APaddlePlayerController::Lanch()
{
	MyBall->Launch();
}

void APaddlePlayerController::SpawnNewBall()
{

	if (!MyBall) {
		MyBall = nullptr;
	}

	if (BallObj) {
		MyBall = GetWorld()->SpawnActor<ABall>(BallObj, SpawnLocation, SpawnRotator, SpawnInfo);
	}


}
