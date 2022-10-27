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

	/*RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));*/

	SM_Brick = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Brick"));
	SM_Brick->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	SM_Brick->SetStaticMesh(BrickMessAsset.Object);

	BoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Collision"));
	BoxCollision->SetBoxExtent(FVector(25.0f, 10.0f, 10.0f));

	RootComponent = BoxCollision;

	/*MoveSpeed = 1000.0f;*/

	direccion = 1;

}

// Called when the game starts or when spawned
void ABrick::BeginPlay()
{
	Super::BeginPlay();
	Velocity = 40.f;
	/*cubo = GetOwner();*/
}

void ABrick::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndexType, bool bFromSweet, const FHitResult& SweepResult)
{
	BoxCollision->OnComponentBeginOverlap.AddDynamic(this, &ABrick::OnOverlapBegin);

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

// Called every frame
void ABrick::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	FVector NewLocation = GetActorLocation();

	if (NewLocation.Z > 400) {
		direccion = direccion * -1;
	}

	if (NewLocation.Z < 260) {
		direccion = direccion * -1;
	}
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

