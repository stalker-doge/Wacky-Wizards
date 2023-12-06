
// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Spell.h"
#include "InputActionValue.h"
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

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Powers")
		float spelltimer1 = 0.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Powers")
		float spelltimer2 = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Powers")
		float spellcooldown1 = 0.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Powers")
		float spellcooldown2 = 0.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Powers")
	class UBoxComponent* spellSpawnPoint;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Powers")
		bool canCastSpell1 = true;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Powers")
		bool canCastSpell2 = true;

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

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Status")
	float slipForce = 2200.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Powers")
	TSubclassOf<ASpell> SpellClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Powers")
		TSubclassOf<ASpell>  SpellClass2;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player")
	int PlayerNumber = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player")
	float maxSpeed = 600.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player")
	float slowSpeed = 300.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Zone")
		bool isZoneKing;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Zone")
		int score;

	UFUNCTION(BlueprintCallable, Category = "Zone")
		void SetZoneKing(bool setZone);


	void MoveX(float AxisValue);
	void MoveY(float AxisValue);
    void TurnCamera(float AxisValue);

	UFUNCTION(BlueprintCallable, Category = "Powers")
	void CastSpell();

	UFUNCTION(BlueprintCallable, Category = "Powers")
		void CastSpell2();

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

		// Handle move input
		void Move(const FInputActionValue& Value);

		// Handle look input
		void Turn(const FInputActionValue& Value);

		UFUNCTION(BlueprintCallable)
			void ChangeSpell(TSubclassOf<ASpell> NewSpell);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Enhanced Input")
	class UInputMappingContext* InputMapping;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Enhanced Input")
	class UInputConfigData* InputActions;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override; 


};
