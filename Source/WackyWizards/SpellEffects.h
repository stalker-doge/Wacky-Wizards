// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Spell.h"
#include "Wizard.h"
#include "SpellEffects.generated.h"

UCLASS()
class WACKYWIZARDS_API ASpellEffects : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpellEffects();

	ASpell* Spell;
	AWizard* Wizard;

	void SpellEffect(ASpell* SpellCasted,AWizard* WizardEffected);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
