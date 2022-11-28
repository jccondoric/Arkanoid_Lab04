// Copyright Epic Games, Inc. All Rights Reserved.


#include "Arkanoid_Lab04GameModeBase.h"
#include "Brick.h"
#include "GunAdapter.h"
#include "Shooter.h"

AArkanoid_Lab04GameModeBase::AArkanoid_Lab04GameModeBase()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AArkanoid_Lab04GameModeBase::BeginPlay()
{
	Super::BeginPlay();
	AGunAdapter* GunAdapter = GetWorld()->SpawnActor<AGunAdapter>(AGunAdapter::StaticClass());
	//Spawn the Shooter and set the Gun Adapter
	Shooter = GetWorld()->SpawnActor<AShooter>(AShooter::StaticClass());
	Shooter->SetSlingShot(GunAdapter);
	//Shoot
	Shooter->Sling();


	const FVector Ubicacion(20.0f, 50.0f,100.0f);
	const FRotator Rotacion(0.0f, 0.0f, 0.0f);

	UWorld* const World = GetWorld();

}

void AArkanoid_Lab04GameModeBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
