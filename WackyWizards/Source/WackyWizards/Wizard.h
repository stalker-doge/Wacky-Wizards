
// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Wizard.generated.h"


UCLASS()
class WACKYWIZARDS_API AWizard : public ACharacter
{
	GENERATED_BODY()


public:
	// Sets default values for this character's properties
	AWizard();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera")
	class USpringArmComponent* CameraBoom;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera")
	class UCameraComponent* FollowCamera;

	UPROPERTY(EditAnywhere, Category = "Player2")
		AWizard* Player2;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Powers")
	float ThrowForce = 1000.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawn")
	FVector SpawnLocation;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Status")
	int lives = 3;


	void MoveX(float AxisValue);
	void MoveY(float AxisValue);
    void TurnCamera(float AxisValue);
	void MoveXPlayer2(float AxisValue);
	void MoveYPlayer2(float AxisValue);

	void ThrowBox();

	void Respawn();

	void Jump();


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override; 


};
