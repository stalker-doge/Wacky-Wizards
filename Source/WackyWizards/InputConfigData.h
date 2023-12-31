// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "InputAction.h"
#include "InputConfigData.generated.h"

/**
 * 
 */
UCLASS()
class WACKYWIZARDS_API UInputConfigData : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UInputAction* InputMove;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UInputAction* InputTurn;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UInputAction* InputCastSpell;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UInputAction* InputWizardJump;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
		UInputAction* InputCast2ndSpell;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
		UInputAction* InputInteract;
	
};
