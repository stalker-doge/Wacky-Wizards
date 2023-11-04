// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Spell.h"
#include "ReverseSpell.generated.h"

/**
 * 
 */
UCLASS()
class WACKYWIZARDS_API AReverseSpell : public ASpell
{
	GENERATED_BODY()

public:

virtual void SpellEffect(class AWizard* wizard) override;
	
};
