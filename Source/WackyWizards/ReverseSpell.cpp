// Fill out your copyright notice in the Description page of Project Settings.


#include "ReverseSpell.h"
#include "Wizard.h"


void AReverseSpell::SpellEffect(AWizard* wizard)
{
	wizard->ReverseControls();
}
