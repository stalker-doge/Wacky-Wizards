
// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Spell.h"
#include "Wizard.generated.h"


UCLASS()
class WACKYWIZARDS_API AWizard : public ACharacter
{
	GENERATED_BODY()


public:
	// Sets default values for this character's properties
	AWizard();


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Powers")
	float ThrowForce = 1000.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawn")
	FVector SpawnLocation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Status")
	int lives = 3;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Status")
	bool isSlowed = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Status")
	bool reverseControls = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Status")
	float reverseControlsTimer = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Status")
	float reverseControlsTimerMax = 3.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Status")
	bool isOnSlipperyGround = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Powers")
	TSubclassOf<ASpell> SpellClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player")
	int PlayerNumber = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player")
	float maxSpeed = 600.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player")
	float slowSpeed = 300.0f;

	void MoveX(float AxisValue);
	void MoveY(float AxisValue);
    void TurnCamera(float AxisValue);

	UFUNCTION(BlueprintCallable, Category = "Powers")
	void CastSpell();

	void LaunchCharacter(FVector LaunchVelocity, bool bXYOverride, bool bZOverride);

	UCharacterMovementComponent* GetCharacterMovement() const;

	void CharacterKnockback();

	void AddMovement(FVector LaunchVelocity);

	UFUNCTION(BlueprintCallable)
	void Respawn();

	UFUNCTION(BlueprintCallable)
		void RespawnAt(FVector RespawnPosition);

	void Jump();

	UFUNCTION(BlueprintCallable)
		void Slow();

	UFUNCTION(BlueprintCallable)
	void UnSlow();

	UFUNCTION(BlueprintCallable)
	void SlipperyGround();

	UFUNCTION(BlueprintCallable)
	void UnSlipperyGround();

	UFUNCTION(BlueprintCallable)
		void ReverseControls();


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override; 


};
