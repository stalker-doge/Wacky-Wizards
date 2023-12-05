// Fill out your copyright notice in the Description page of Project Settings.


#include "KingOfTheHillZone.h"
#include "Components/BoxComponent.h"
#include "Wizard.h"

// Sets default values
AKingOfTheHillZone::AKingOfTheHillZone()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	zoneBox = CreateDefaultSubobject<UBoxComponent>(TEXT("ZoneBox"));
	zoneBox->SetupAttachment(RootComponent);
	zoneBox->SetCollisionProfileName(TEXT("Trigger"));
	zoneBox->SetGenerateOverlapEvents(true);
	zoneBox->OnComponentBeginOverlap.AddDynamic(this, &AKingOfTheHillZone::OnOverlapBegin);
	zoneBox->OnComponentEndOverlap.AddDynamic(this, &AKingOfTheHillZone::OnOverlapEnd);


}

void AKingOfTheHillZone::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	AWizard* wizard = Cast<AWizard>(OtherActor);
	if (wizard)
	{
		playersInZone++;
		if (playersInZone == 1)
		{
			//UE_LOG(LogTemp, Warning, TEXT("WHUH"));
			wizard->SetZoneKing(true);
			wizardsInZone.AddUnique(wizard);
			currentKing = wizard;
		}
		if (playersInZone > 1)
		{
			currentKing->SetZoneKing(false);
			wizardsInZone.AddUnique(wizard);
		}
	}


}

void AKingOfTheHillZone::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	AWizard* wizard = Cast<AWizard>(OtherActor);
	if (wizard)
	{
		playersInZone--;
		if (currentKing == wizard)
		{
			currentKing->SetZoneKing(false);
			wizardsInZone.Remove(wizard);
			if (playersInZone == 1)
			{
				wizardsInZone[0]->SetZoneKing(true);
				currentKing = wizardsInZone[0];
			}
		}
	}
}

//// Called when the game starts or when spawned
//void AKingOfTheHillZone::BeginPlay()
//{
//	Super::BeginPlay();
//	
//}
//
//// Called every frame
//void AKingOfTheHillZone::Tick(float DeltaTime)
//{
//	Super::Tick(DeltaTime);
//
//}

