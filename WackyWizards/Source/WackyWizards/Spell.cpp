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

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetSimulatePhysics(true);

	CollisionSphere = CreateDefaultSubobject<USphereComponent>(TEXT("Collision Sphere"));
	CollisionSphere->InitSphereRadius(50.0f);
	CollisionSphere->SetCollisionProfileName(TEXT("Trigger"));
	CollisionSphere->SetGenerateOverlapEvents(true);
	RootComponent= CollisionSphere;
	Mesh->SetupAttachment(RootComponent);
}


void ASpell::OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) 
{

	AWizard* wizard = Cast<AWizard>(OtherActor);
	if (wizard)
	{

		//wizard->Respawn();
		wizard->LaunchCharacter(FVector(-1000, 0, 0), false, false);
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
	CollisionSphere->OnComponentBeginOverlap.AddDynamic(this, &ASpell::OnOverlapBegin);
}

// Called every frame
void ASpell::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//destroys the spell after a certain amount of time
	lifeTime -= DeltaTime;
	if (lifeTime <= 0)
	{
		Destroy();
	}
}

