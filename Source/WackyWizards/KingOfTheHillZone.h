// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "KingOfTheHillZone.generated.h"

UCLASS()
class WACKYWIZARDS_API AKingOfTheHillZone : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AKingOfTheHillZone();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Zone")
		class UBoxComponent* zoneBox;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Zone")
		class AWizard* currentKing;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Zone")
		TArray<AWizard*> wizardsInZone;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Zone")
		int playersInZone;


	UFUNCTION(BlueprintCallable)
		void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp,
			int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION(BlueprintCallable)
		void OnOverlapEnd(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp,
			int32 OtherBodyIndex);



protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
