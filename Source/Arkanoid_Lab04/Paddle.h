// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Paddle.generated.h"

class UFloatingPawnMovement;//Declaracion antecedida, es una clase
UCLASS()
class ARKANOID_LAB04_API APaddle : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APaddle();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//Malla (Mascara vestir al Actor)
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)//Imagen Apariencia
		UStaticMeshComponent* SM_Paddle;//Objeto que va permitir maniular los objeto estaticos
	//Componente Gesiona como se mueve este Componente
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		UFloatingPawnMovement* FloatingMovement;//Movimiento de flotacion



public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	//virtual por que  Cuando la hereden sus clases hijas puedan modificarla (Recarguen)
	virtual void Move(float _AxisValue);//Funcion para Mover la Paleta

};
