// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Spell.h"
#include "IceTrail.h"
#include "IceSpell.generated.h"

/**
 * 
 */
UCLASS()
class WACKYWIZARDS_API AIceSpell : public ASpell
{
	GENERATED_BODY()

	public:
	AIceSpell();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Powers")
	TSubclassOf<AIceTrail> IceTrailClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Powers")
	float spawnTime = 0.5f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Powers")
	float spawnTimer = 0.0f;

		virtual void SpellEffect(class AWizard* wizard) override;
		virtual void SpellCast() override;
		virtual void Tick(float DeltaTime) override;
	
};
