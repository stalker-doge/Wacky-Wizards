// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Spell.generated.h"

UCLASS()
class WACKYWIZARDS_API ASpell : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpell();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Powers")
	float ThrowForce = 1000.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Powers")
	float Damage = 10.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Powers")
	float Knockback = 100.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Collision")
	class USphereComponent* CollisionSphere;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mesh")
	class UStaticMeshComponent* Mesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
	float lifeTime = 5.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
	float cooldown = 3.0f;
	
	UFUNCTION(BlueprintCallable)
		void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp,
			int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);


	UFUNCTION()
		float GetCooldown();

	UFUNCTION()
	virtual void SpellCast();

	UFUNCTION()
	void SpellSideEffectCast();

	UFUNCTION(BlueprintCallable)
		virtual void SpellEffect(class AWizard* wizard);

	UStaticMeshComponent* GetMesh() { return Mesh; }

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Side Effects")
	float sideEffectChance = 10.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Side Effects")
	TArray<TSubclassOf<class ASpell>> sideEffects;

	UFUNCTION(BlueprintCallable)
		virtual void SideEffect();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
