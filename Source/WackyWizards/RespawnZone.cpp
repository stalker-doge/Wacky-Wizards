// Fill out your copyright notice in the Description page of Project Settings.


#include "RespawnZone.h"
#include "Components/BoxComponent.h"
#include "WackyWizards/Wizard.h"

// Sets default values
ARespawnZone::ARespawnZone()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	spawnBox = CreateDefaultSubobject<UBoxComponent>(TEXT("SpawnBox"));
	spawnBox->SetupAttachment(RootComponent);
	spawnBox->SetCollisionProfileName(TEXT("Trigger"));
	spawnBox->SetGenerateOverlapEvents(true);
	spawnBox->OnComponentBeginOverlap.AddDynamic(this, &ARespawnZone::OnOverlapBegin);


}

// Called when the game starts or when spawned
void ARespawnZone::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARespawnZone::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ARespawnZone::OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	AWizard* wizard = Cast<AWizard>(OtherActor);
	if (wizard)
	{
		wizard->Respawn();
		if (useLives)
		{
			wizard->lives--;
		}
	}
}

