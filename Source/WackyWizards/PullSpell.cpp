// Fill out your copyright notice in the Description page of Project Settings.


#include "PullSpell.h"
#include "WackyWizards/Wizard.h"

void APullSpell::SpellEffect(AWizard* wizard)
{
	//pulls the wizard back
	FVector LaunchDirection = wizard->GetActorLocation() - GetActorLocation();
	LaunchDirection.Normalize();
	wizard->LaunchCharacter(LaunchDirection * -Knockback, true, true);
	Destroy();
}
