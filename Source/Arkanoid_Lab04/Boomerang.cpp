// Fill out your copyright notice in the Description page of Project Settings.


#include "Boomerang.h"

// Sets default values
ABoomerang::ABoomerang()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SM_Boomerang = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SM Boomerang"));
	direccion = 1;
}

void ABoomerang::Lanzar()
{
}

// Called when the game starts or when spawned
void ABoomerang::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABoomerang::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


	FVector NewLocation = GetActorLocation();


	//comprueba si el Brick ha superado la marca de 400 unidades
	if (NewLocation.Z > 400) {

		//si es así... invierte su dirección actual ....
		//esto hará que baje si se establece inicialmente en 1 y se inicializa para estar dentro del movimiento
		direccion = direccion * -1;
	}
	//comprueba si el Brick ha bajado de la marca de 260 unidades
	if (NewLocation.Z < 260) {

		//si el brikk está a menos de 260 unidades debería empezar a subir
		direccion = direccion * -1;
	}
	//reasignando la NuevaLocalización para que se mueva 0,4 unidades en la dirección
	NewLocation.Z += direccion * 0.4f;

	SetActorLocation(NewLocation);
}

void ABoomerang::Regresar()
{
}

