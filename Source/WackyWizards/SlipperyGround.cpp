// Fill out your copyright notice in the Description page of Project Settings.


#include "SlipperyGround.h"
#include "Wizard.h"

void ASlipperyGround::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	//checks if the other actor is a wizard, then sets them to be slippery
	if (OtherActor->IsA(AWizard::StaticClass()))
	{
		AWizard* Wizard = Cast<AWizard>(OtherActor);
		Wizard->SlipperyGround();
	}
}

void ASlipperyGround::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (OtherActor->IsA(AWizard::StaticClass()))
	{
		AWizard* Wizard = Cast<AWizard>(OtherActor);
		Wizard->UnSlipperyGround();
	}
}
