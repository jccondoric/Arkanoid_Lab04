// Fill out your copyright notice in the Description page of Project Settings.


#include "ControlFunction.h"
#include "Brick.h"
#include "Ball.h"
#include "Paddle.h"
#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"
#include "PaddlePlayerController.h"

// Sets default values
AControlFunction::AControlFunction()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AControlFunction::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AControlFunction::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

