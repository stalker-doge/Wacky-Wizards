// Fill out your copyright notice in the Description page of Project Settings.


#include "Wizard.h"
#include "Components/SkeletalMeshComponent.h"
#include "Components/CapsuleComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "InputMappingContext.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "InputConfigData.h"


// Sets default values
AWizard::AWizard()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

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

	//while the wizard is on slippery ground, it will keep sliding
	if (isOnSlipperyGround)
	{
		//gets the current velocity of the wizard
	FVector currentVelocity = GetCharacterMovement()->Velocity;
	//adds a force to the wizard to keep it moving
	GetCharacterMovement()->AddForce(currentVelocity * slipForce);
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

void AWizard::Move(const FInputActionValue& Value)
{
	if (Controller != nullptr)
	{
		//moves the wizard in absolute directions, ignoring the direction the wizard is facing

        const FVector2D MoveValue = Value.Get<FVector2D>();
		if (MoveValue.X != 0.f)
		{
			AddMovementInput(FVector(0.f, 1.f, 0.f), MoveValue.X);
		}
		if (MoveValue.Y != 0.f)
		{
			AddMovementInput(FVector(1.f, 0.f, 0.f), MoveValue.Y);
		}

	}
}

void AWizard::Turn(const FInputActionValue& Value)
{
	if (Controller != nullptr)
	{
		const FVector2D LookValue = Value.Get<FVector2D>();

		if (LookValue.X != 0.f)
		{
			AddControllerYawInput(LookValue.X);
		}

		if (LookValue.Y != 0.f)
		{
			AddControllerPitchInput(LookValue.Y);
		}
	}
}

// Called to bind functionality to input
void AWizard::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	//Super::SetupPlayerInputComponent(PlayerInputComponent);
	//InputComponent->BindAxis("MoveForward", this, &AWizard::MoveX);
	//InputComponent->BindAxis("MoveRight", this, &AWizard::MoveY);

	//InputComponent->BindAxis("Turn", this, &AWizard::TurnCamera);

	//InputComponent->BindAction("Jump", IE_Pressed, this, &AWizard::Jump);
	//InputComponent->BindAction("CastSpell", IE_Pressed, this, &AWizard::CastSpell);

	// Get the player controller
	APlayerController* PC = Cast<APlayerController>(GetController());

	//Get the local player subsystem
	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PC->GetLocalPlayer());

	//Clear out the existing mappings, and add our mapping
	Subsystem->ClearAllMappings();
	Subsystem->AddMappingContext(InputMapping, 0);

	//Get the Enhanced Input Component
	UEnhancedInputComponent* PEI = Cast<UEnhancedInputComponent>(PlayerInputComponent);
	// Bind the actions
	PEI->BindAction(InputActions->InputMove, ETriggerEvent::Triggered, this, &AWizard::Move);
	PEI->BindAction(InputActions->InputTurn, ETriggerEvent::Triggered, this, &AWizard::Turn);
	PEI->BindAction(InputActions->InputCastSpell, ETriggerEvent::Triggered, this, &AWizard::CastSpell);
	PEI->BindAction(InputActions->InputWizardJump, ETriggerEvent::Triggered, this, &AWizard::Jump);
}