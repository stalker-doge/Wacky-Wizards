// Fill out your copyright notice in the Description page of Project Settings.


#include "Wizard.h"
#include "Components/SkeletalMeshComponent.h"
#include "Components/CapsuleComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"


// Sets default values
AWizard::AWizard()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//assings an available controller to the wizard
	switch (PlayerNumber)
	{
		case 0:
			AutoPossessPlayer = EAutoReceiveInput::Player0;
			break;

		case 1:
			AutoPossessPlayer = EAutoReceiveInput::Player1;
			break;

		case 2:
			AutoPossessPlayer = EAutoReceiveInput::Player2;
			break;

		case 3:
			AutoPossessPlayer = EAutoReceiveInput::Player3;
			break;
	}

}
void AWizard::MoveX(float AxisValue)
{
	if(reverseControls)
	AddMovementInput(GetActorForwardVector() * -AxisValue);
	else
		AddMovementInput(GetActorForwardVector() * AxisValue);
}

void AWizard::MoveY(float AxisValue)
{
	if (reverseControls)
		AddMovementInput(GetActorRightVector() * -AxisValue);
	else
	AddMovementInput(GetActorRightVector() * AxisValue);
}

void AWizard::TurnCamera(float AxisValue)
{
	AddControllerYawInput(AxisValue);
	AddActorLocalRotation(FRotator(0, AxisValue, 0));
}


void AWizard::CastSpell()
{
	if (SpellClass)
	{
		//spawns the spell
		FVector spellSpawnLocation = GetActorLocation() + GetActorForwardVector() * 100.0f;
		FRotator SpawnRotation = GetActorRotation();
		ASpell* Spell = GetWorld()->SpawnActor<ASpell>(SpellClass, spellSpawnLocation, SpawnRotation);
		Spell->SetOwner(this);
		Spell->GetMesh()->SetSimulatePhysics(true);
		//sets the spell's location in front of the wizard
		Spell->GetMesh()->SetWorldLocation(spellSpawnLocation);
		Spell->GetMesh()->AddImpulse(GetActorForwardVector() *	ThrowForce, NAME_None, true);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("SpellClass is not valid"));
	}
}

void AWizard::LaunchCharacter(FVector LaunchVelocity, bool bXYOverride, bool bZOverride)
{
	//launches the character backwards when hit by a spel;
	ACharacter::LaunchCharacter(LaunchVelocity, bXYOverride, bZOverride);
}

UCharacterMovementComponent* AWizard::GetCharacterMovement() const
{
	//gets the character movement component
	return ACharacter::GetCharacterMovement();
}


void AWizard::CharacterKnockback()
{
	LaunchCharacter(FVector(-1000, 0, 0), false, false);

}

void AWizard::AddMovement(FVector LaunchVelocity)
{
	//adds movement to the character
	AddMovementInput(LaunchVelocity);
}


void AWizard::Respawn()
{
	SetActorLocation(SpawnLocation);
}

void AWizard::RespawnAt(FVector RespawnPosition)
{

}

// Called when the game starts or when spawned
void AWizard::BeginPlay()
{
	Super::BeginPlay();

	SpawnLocation = GetActorLocation();// sets the spawn location to the location of the wizard at the start of the game

	
}

// Called every frame
void AWizard::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if(isSlowed)
		GetCharacterMovement()->MaxWalkSpeed = slowSpeed;
	else
		GetCharacterMovement()->MaxWalkSpeed = maxSpeed;

	if (reverseControls)
	{
		reverseControlsTimer += DeltaTime;
		if (reverseControlsTimer >= reverseControlsTimerMax)
		{
			reverseControls = false;
			reverseControlsTimer = 0;
		}
	}

}

void AWizard::Jump()
{
	ACharacter::Jump();
}

void AWizard::Slow()
{
	isSlowed = true;
}

void AWizard::UnSlow()
{
	isSlowed = false;
}

void AWizard::SlipperyGround()
{
	isOnSlipperyGround = true;
}

void AWizard::UnSlipperyGround()
{
	isOnSlipperyGround = false;
}

void AWizard::ReverseControls()
{
	reverseControls = true;
}

// Called to bind functionality to input
void AWizard::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	InputComponent->BindAxis("MoveForward", this, &AWizard::MoveX);
	InputComponent->BindAxis("MoveRight", this, &AWizard::MoveY);

	InputComponent->BindAxis("Turn", this, &AWizard::TurnCamera);

	InputComponent->BindAction("Jump", IE_Pressed, this, &AWizard::Jump);
	InputComponent->BindAction("CastSpell", IE_Pressed, this, &AWizard::CastSpell);
}