// Fill out your copyright notice in the Description page of Project Settings.


#include "IceSpell.h"

AIceSpell::AIceSpell()
{
}

void AIceSpell::SpellEffect(AWizard* wizard)
{

}

void AIceSpell::SpellCast()
{
	//launches the spell forward
	FVector LaunchDirection = GetActorForwardVector();
	LaunchDirection.Normalize();
	CollisionSphere->AddImpulse(LaunchDirection * ThrowForce, NAME_None, true);
}

void AIceSpell::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//destroys the spell after a certain amount of time
	lifeTime -= DeltaTime;
	if (lifeTime <= 0)
	{
		Destroy();
	}
	CollisionSphere->SetWorldLocation(Mesh->GetComponentLocation());

	//spawns the ice trail after a certain amount of time
	spawnTimer+=DeltaTime;
	if (spawnTimer >= spawnTime)
	{
		//puts a rayscan to the ground 
		FHitResult hit;
		FVector start = GetActorLocation();
		FVector end = GetActorLocation() - FVector(0, 0, 100);
		FCollisionQueryParams traceParams;
		traceParams.AddIgnoredActor(this);
		//if it hits an ice trail, it will destroy the ice trail
		if (GetWorld()->LineTraceSingleByChannel(hit, start, end, ECC_Visibility, traceParams))
		{
			AIceTrail* iceTrail = Cast<AIceTrail>(hit.GetActor());
			if (iceTrail)
			{
				iceTrail->Destroy();
			}
		}
		GetWorld()->LineTraceSingleByChannel(hit, start, end, ECC_Visibility, traceParams);
        //spawns the ice trail
		FVector spawnLocation = hit.ImpactPoint + FVector(0, 0, 2);
		AIceTrail* iceTrail = GetWorld()->SpawnActor<AIceTrail>(IceTrailClass, spawnLocation, GetActorRotation());
		spawnTimer = 0.0f;
	}
}
