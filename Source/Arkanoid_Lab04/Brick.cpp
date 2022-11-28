// Fill out your copyright notice in the Description page of Project Settings.


#include "Brick.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "Ball.h"
#include "UObject/ConstructorHelpers.h"

// Sets default values
ABrick::ABrick()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	static ConstructorHelpers::FObjectFinder<UStaticMesh> BrickMessAsset(TEXT("StaticMesh'/Game/Meshes/SM_Brick.SM_Brick'"));
	SM_Brick = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Brick"));
	RootComponent = SM_Brick;
	SM_Brick->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	SM_Brick->SetStaticMesh(BrickMessAsset.Object);

	BoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Collision"));
	BoxCollision->SetBoxExtent(FVector(25.0f, 10.0f, 10.0f));

	RootComponent = BoxCollision;

	/*MoveSpeed = 1000.0f;*/


	//poner la dirección en 1
	direccion = 1;

	VidaBrick = 10;
	ValorPuntaje = 50;
}

// Called when the game starts or when spawned
void ABrick::BeginPlay()
{
	Super::BeginPlay();
	BoxCollision->OnComponentBeginOverlap.AddDynamic(this, &ABrick::OnOverlapBegin);
	Velocity = 40.f;
	/*cubo = GetOwner();*/
}

void ABrick::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndexType, bool bFromSweet, const FHitResult& SweepResult)
{
	

	if (OtherActor->ActorHasTag("Ball")) {
		ABall* MyBall = Cast<ABall>(OtherActor);

		FVector BallVelocity = MyBall->GetVelocity();
		BallVelocity *= (SpeedModifierOnBounce - 1.0f);

		MyBall->GetBall()->SetPhysicsLinearVelocity(BallVelocity, true);

		this->Destroy();
	}

}

void ABrick::DestroyBrick()
{
	this->Destroy();
}

void ABrick::EnergyBrick(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndexType, bool bFromSweet, const FHitResult& SweepResult)
{
	float Score = 0 ;

	if (OtherActor->ActorHasTag("Ball")) {
		
		VidaBrick--;
		
		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow,FString::Printf(TEXT("Reducio la Energia")));

		if(VidaBrick == 0){
			
		this->Destroy();
		Score+=ValorPuntaje;
		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("XD")));
		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("Se destruyo el Brick")));

		}
	}


}



// Called every frame
void ABrick::Tick(float DeltaTime)
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
	 NewLocation.Z += direccion * 0.4f;

	 SetActorLocation(NewLocation);

	//const FVector MoveDirection = FVector(0.f, 1.f, -1.f);//Direccion
	//const FVector Movement = NewLocation * Velocity * DeltaTime;//Velocidad Brick

	//if (Movement.SizeSquared() > 0.0f) {
	//	const FRotator NewRotation = FRotator(0.0f, -90.0f, 0.0f); 

	//	FHitResult Hit(1.0f);
	//	RootComponent->MoveComponent(Movement, NewRotation, true, &Hit);
	//}

}

