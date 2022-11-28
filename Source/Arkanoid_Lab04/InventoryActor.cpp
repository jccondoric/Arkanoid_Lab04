// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryActor.h"

AInventoryActor::AInventoryActor():Super() 
{
	PrimaryActorTick.bCanEverTick = true;
	

	auto MeshAsset = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Engine/BasicShapes/Sphere.Sphere'"));

	if (MeshAsset.Object != nullptr) { //crear  su apariencia 

		GetStaticMeshComponent()->SetStaticMesh(MeshAsset.Object);//Esa forma de cubo le estamos asignando al objeto
		GetStaticMeshComponent()->SetCollisionProfileName(UCollisionProfile::Pawn_ProfileName);//Variable para las colisiones
	}

	GetStaticMeshComponent()->SetMobility(EComponentMobility::Movable); //Para que se pueda mover
	SetActorEnableCollision(true);//Activar las collisiones
}

void AInventoryActor::BeginPlay()
{
	Super::BeginPlay();
}

void AInventoryActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AInventoryActor::PickUp()//Recoger, cuando el paddle choque con el objeto el paddle se lo va ha comer
{
	
	SetActorTickEnabled(false);//Cuando el Paddle como el objeto No necesitamos el Tick(el tick actualiza un estado) 
	SetActorHiddenInGame(true);//Para ocultar el objeto cuando se lo coma el Paddle 
	SetActorEnableCollision(false);//como se le comio entonces va ha estar false collision
}

void AInventoryActor::PutDown(FTransform TargetLocation)//Para nuestro juego no seria volver a poner el objeto comido en el escenario
{

	SetActorTickEnabled(true);
	SetActorHiddenInGame(false);
	SetActorEnableCollision(true);
	SetActorLocation(TargetLocation.GetLocation());//Establecer su nueva ubicacion, lo va ubicar donde yo lo diga
}



 