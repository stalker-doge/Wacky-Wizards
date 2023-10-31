// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Spell.h"
#include "PullSpell.generated.h"

/**
 * 
 */
UCLASS()
class WACKYWIZARDS_API APullSpell : public ASpell
{
	GENERATED_BODY()

public:
		void SpellEffect(class AWizard* wizard) override;
	
};
