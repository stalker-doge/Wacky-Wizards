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


}
void AWizard::MoveX(float AxisValue)
{
	AddMovementInput(GetActorForwardVector() * AxisValue);
}

void AWizard::MoveY(float AxisValue)
{
	AddMovementInput(GetActorRightVector() * AxisValue);
}

void AWizard::TurnCamera(float AxisValue)
{
	AddControllerYawInput(AxisValue);
	AddActorLocalRotation(FRotator(0, AxisValue, 0));
}

void AWizard::MoveXPlayer2(float AxisValue)
{
	if (Player2->IsValidLowLevel())
	{
		Player2->MoveX(AxisValue);
	}
}

void AWizard::MoveYPlayer2(float AxisValue)
{
	if (Player2->IsValidLowLevel())
	{
		Player2->MoveY(AxisValue);
	}
}
void AWizard::TurnCameraPlayer2(float AxisValue)
{
	if (Player2->IsValidLowLevel())
	{
		Player2->TurnCamera(AxisValue);
	}
}
void AWizard::JumpPlayer2()
{
	if (Player2->IsValidLowLevel())
	{
		Player2->Jump();
	}
}
void AWizard::CastSpellPlayer2()
{
	if (Player2->IsValidLowLevel())
	{
		Player2->CastSpell();
	}
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
	//launches the character backwards when hit by a spell
	UE_LOG(LogTemp, Warning, TEXT("Hit"));
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
}

void AWizard::Jump()
{
	ACharacter::Jump();
}

// Called to bind functionality to input
void AWizard::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	InputComponent->BindAxis("MoveForward", this, &AWizard::MoveX);
	InputComponent->BindAxis("MoveRight", this, &AWizard::MoveY);

	InputComponent->BindAxis("MoveForwardPlayer2", this, &AWizard::MoveXPlayer2);
	InputComponent->BindAxis("MoveRightPlayer2", this, &AWizard::MoveYPlayer2);
	InputComponent->BindAxis("Turn", this, &AWizard::TurnCamera);
	InputComponent->BindAxis("TurnPlayer2", this, &AWizard::TurnCameraPlayer2);

	InputComponent->BindAction("Jump", IE_Pressed, this, &AWizard::Jump);
	InputComponent->BindAction("CastSpell", IE_Pressed, this, &AWizard::CastSpell);
	InputComponent->BindAction("Jump Player2", IE_Pressed, this, &AWizard::JumpPlayer2);
	InputComponent->BindAction("CastSpell Player2", IE_Pressed, this, &AWizard::CastSpellPlayer2);
}