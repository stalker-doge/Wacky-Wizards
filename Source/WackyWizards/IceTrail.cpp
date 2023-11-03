// Fill out your copyright notice in the Description page of Project Settings.


#include "IceTrail.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "WackyWizards/Wizard.h"

// Sets default values
AIceTrail::AIceTrail()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
    CollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("Collision Box"));
	CollisionBox->SetCollisionProfileName("Trigger");
	CollisionBox->SetGenerateOverlapEvents(true);
	CollisionBox->OnComponentBeginOverlap.AddDynamic(this, &AIceTrail::OnOverlapBegin);
	CollisionBox->OnComponentEndOverlap.AddDynamic(this, &AIceTrail::OnOverlapEnd);
	RootComponent = CollisionBox;
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(CollisionBox);
}

void AIceTrail::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	//if it's a wizard, slows it down 
    AWizard* wizard = Cast<AWizard>(OtherActor);
	if (wizard)
	{
		wizard->Slow();
	}
}

void AIceTrail::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	//if it's a wizard, unslows it
	AWizard* wizard = Cast<AWizard>(OtherActor);
	if (wizard)
	{
		wizard->UnSlow();
	}
}

// Called when the game starts or when spawned
void AIceTrail::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AIceTrail::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	lifeTime -= DeltaTime;
	if (lifeTime <= 0)
	{
		Destroy();
	}

}

