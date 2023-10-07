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

CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
CameraBoom->SetupAttachment(GetCapsuleComponent());
CameraBoom->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
CameraBoom->TargetArmLength = 300.0f;
CameraBoom->bUsePawnControlRotation = true;

FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
FollowCamera->bUsePawnControlRotation = false;

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
}

// Called when the game starts or when spawned
void AWizard::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AWizard::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AWizard::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	InputComponent->BindAxis("MoveForward", this, &AWizard::MoveX);
	InputComponent->BindAxis("MoveRight", this, &AWizard::MoveY);
InputComponent->BindAxis("Turn", this, &AWizard::TurnCamera);

}



