// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Wizard.h"
#include "WizardController.generated.h"

/**
 * 
 */
UCLASS()
class WACKYWIZARDS_API AWizardController : public APlayerController
{
	GENERATED_BODY()



protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;



public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	
};
