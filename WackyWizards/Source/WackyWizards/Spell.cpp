// Fill out your copyright notice in the Description page of Project Settings.


#include "Spell.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "WackyWizards/Wizard.h"

// Sets default values
ASpell::ASpell()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CollisionSphere = CreateDefaultSubobject<USphereComponent>(TEXT("Collision Sphere"));
	CollisionSphere->InitSphereRadius(50.0f);
	CollisionSphere->SetCollisionProfileName(TEXT("Trigger"));
	CollisionSphere->SetGenerateOverlapEvents(true);
	CollisionSphere->OnComponentBeginOverlap.AddDynamic(this, &ASpell::OnOverlapBegin);

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(RootComponent);
	Mesh->SetSimulatePhysics(true);

}


void ASpell::OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) 
{

	if (OtherActor->IsA(AWizard::StaticClass()))
	{
		AWizard* Wizard = Cast<AWizard>(OtherActor);
		if (Wizard->IsValidLowLevel())
		{
			UE_LOG(LogTemp, Warning, TEXT("Wizard is valid"));
			//pushes the player back
			FVector LaunchDirection = Wizard->GetActorLocation() - GetActorLocation();
			LaunchDirection.Normalize();
			Wizard->LaunchCharacter(LaunchDirection * Knockback, true, true);
			Destroy();
		}
	}

}

void ASpell::SpellCast()
{
	//launches the spell forward
	FVector LaunchDirection = GetActorForwardVector();
	LaunchDirection.Normalize();
	Mesh->AddImpulse(LaunchDirection * ThrowForce, NAME_None, true);
}


// Called when the game starts or when spawned
void ASpell::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASpell::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

