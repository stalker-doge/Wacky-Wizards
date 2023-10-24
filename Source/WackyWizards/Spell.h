// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
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

	UFUNCTION(BlueprintCallable)
	void OnHit(class UPrimitiveComponent* HitComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp,
		FVector NormalImpulse, const FHitResult& Hit);


	UFUNCTION()
	void SpellCast();

	UFUNCTION(BlueprintCallable)
		void SpellEffect(class AWizard* wizard);

	UStaticMeshComponent* GetMesh() { return Mesh; }

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
