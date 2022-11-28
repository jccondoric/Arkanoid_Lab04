	// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Brick.generated.h"
class UBoxComponent;
UCLASS()
class ARKANOID_LAB04_API ABrick : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABrick();

	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadWrite)
		float MoveSpeed;//Velocidad para que se mueva

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		UStaticMeshComponent* SM_Brick;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		UBoxComponent* BoxCollision;
	float SpeedModifierOnBounce = 1.01f;
	UFUNCTION()
		void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndexType, bool bFromSweet, const FHitResult& SweepResult);

	void DestroyBrick();
protected:
	UFUNCTION()
	void EnergyBrick(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndexType, bool bFromSweet, const FHitResult& SweepResult);
	//////////////////////////
private:
	float Velocity;
public:
	float VidaBrick;
	float ValorPuntaje;
//private:
//	ABrick* cubo;
//	FVector posiciones;
//	UPROPERTY(EditAnywhere)
//	int velocidad = 1;


public:	
	//esta es una propiedad del objeto que se vincula a la variable de dirección en el Brick.cpp 
	int direccion;
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	/*static const FName MoveForwardBinding;
	static const FName MoveRightBinding;*/

};
