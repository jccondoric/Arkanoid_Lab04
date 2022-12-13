// Fill out your copyright notice in the Description page of Project Settings.


#include "Ball.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Math/Vector.h"

// Sets default values
ABall::ABall()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SM_Ball = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Ball"));
	RootComponent = SM_Ball;

	SM_Ball->SetSimulatePhysics(true);
	SM_Ball->SetEnableGravity(false);
	SM_Ball->SetConstraintMode(EDOFMode::XZPlane);
	SM_Ball->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	SM_Ball->SetCollisionProfileName(TEXT("PhysicsActor"));
	
	
	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Projectile Movement "));

	ProjectileMovement->bShouldBounce = true;
	ProjectileMovement->Bounciness = 1.1f;
	ProjectileMovement->Friction = 0.0f;
	ProjectileMovement->Velocity.X = 0.0f;
	//////////////////////////////

	 /*Dimensions =  FVector(300, 0, 0);
	 AxisVector = FVector(0, 0, 1);*/
	AngleAxis = 0;
	direccion = 1;
}

// Called when the game starts or when spawned
void ABall::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


	//FVector Newlocation = FVector(10.0f, 0.0f, 40.0f);

	//FVector Radius = FVector(10, 0, 0);

	//AngleAxis++;

	//if (AngleAxis > 360.f) {

	//	AngleAxis = 1;
	//}

	//FVector RotateValue = Radius.RotateAngleAxis(AngleAxis, FVector(0, 0, 1));

	//Newlocation.X += RotateValue.X;
	//Newlocation.Y += RotateValue.Y;
	//Newlocation.Z += RotateValue.Z;
	//SetActorLocation(Newlocation);


	/////////////////////////////////////////////
	/*FVector NewLocation = FVector(0, 0, 800);

	AngleAxis += DeltaTime * Multiplier;

	if (AngleAxis >= 360.0f) AngleAxis = 0;

	FVector RotateValue = Dimensions.RotateAngleAxis(AngleAxis, AxisVector);

	if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("RotateValue: %s"), *RotateValue.ToString()));
	if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("AngleAxis: %f"), AngleAxis));

	NewLocation.X += RotateValue.X;
	NewLocation.Y += RotateValue.Y;
	NewLocation.Z += RotateValue.Z;

	SetActorLocation(NewLocation, false, 0, ETeleportType::None);*/
	
}

void ABall::Launch()
{
		if (!BallLaunched) {
		
			SM_Ball->AddImpulse(FVector(140.0f, 0.0f, 130.0f), FName(), true);
			BallLaunched = true;

		
		}
}

UStaticMeshComponent* ABall::GetBall()
{
	return SM_Ball;
}

