// Copyright Epic Games, Inc. All Rights Reserved.


#include "Arkanoid_Lab04GameModeBase.h"
#include "Brick.h"
void AArkanoid_Lab04GameModeBase::BeginPlay()
{
	Super::BeginPlay();


	const FVector Ubicacion(20.0f, 50.0f,100.0f);
	const FRotator Rotacion(0.0f, 0.0f, 0.0f);

	UWorld* const World = GetWorld();

	if (World != nullptr) {
		//Spawn o generacion  o creacion  de actores en tiempo de ejecucion
		ladrillo = World->SpawnActor<ABrick>(Ubicacion, Rotacion);
		ladrillo->SetHidden(false);
		GEngine->AddOnScreenDebugMessage(-1, -1, FColor::Cyan, TEXT("Actor ladrillo Creado"));
	};

}
