// Fill out your copyright notice in the Description page of Project Settings.


#include "SpellEffects.h"

// Sets default values
ASpellEffects::ASpellEffects()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void ASpellEffects::SpellEffect(ASpell* SpellCasted, AWizard* WizardEffected)
{
	//pushes the wizard back if they are hit by a spell
	WizardEffected->LaunchCharacter(FVector(-1000, 0, 0), false, false);
}

// Called when the game starts or when spawned
void ASpellEffects::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASpellEffects::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

