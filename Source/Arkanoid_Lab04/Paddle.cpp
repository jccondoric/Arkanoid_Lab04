// Fill out your copyright notice in the Description page of Project Settings.


#include "Paddle.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "Components/StaticMeshComponent.h"
#include "NavMesh/NavMeshBoundsVolume.h"
#include "Components/PrimitiveComponent.h"


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
	
	//
	FloatingMovement = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("Flaoting pow movement"));
	
	direccion = 1;


	//Inventario
	PaddleInventory = CreateDefaultSubobject<UInventoryComponent>(TEXT("Paddle Inventory"));

}

// Called when the game starts or when spawned
void APaddle::BeginPlay()
{
	Super::BeginPlay();
	
}

void APaddle::TakeItem(AInventoryActor* InventoryItem)
{
	InventoryItem->PickUp();//Le estoy diciendo a este objeto  que tiene que desaparecer dejar hacer los ticks y sus collisiones se desactiva
	PaddleInventory->AddToInventory(InventoryItem);
}

void APaddle::DropItem()
{	

}

void APaddle::NotifyHit(UPrimitiveComponent* MyComp, AActor* Other, UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit)
{
	AInventoryActor* InventoryItem = Cast<AInventoryActor>(Other);

	if (InventoryItem != nullptr) {
		TakeItem(InventoryItem);
	}
}

// Called every frame
void APaddle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//crear una nueva ubicación que se modificará
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
	/*NewLocation.Z += direccion * 0.4f;*/

	SetActorLocation(NewLocation);

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

	FVector NewLocation = GetActorLocation();

	AddMovementInput(FVector(_AxisValue, 0.0f, 0.0f ), 1.0f, false);
}

void APaddle::MoveVer(float _VerAxisValue)
{
	//LLamando al metodo addmovementimput
	/*Crea un vector con el valor que va a recoger del eje x, va a crear un vector y le va aplicar moviento
	al objeto de entrada(Pawn objeto de entrada)
	*/
	FVector NewLocation = GetActorLocation();
	AddMovementInput(FVector(0.0f, 0.0f, _VerAxisValue), 1.0f, false);
	

}

