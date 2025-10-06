// Fill out your copyright notice in the Description page of Project Settings.


#include "StaminaComponent.h"

// Sets default values for this component's properties
UStaminaComponent::UStaminaComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	MaxStamina = 100.0f;
	CurrentStamina = MaxStamina;
	RecoveryRate = 10.0f;
	DrainRate = 20.0f;
	bIsSprinting = false;
}


// Called when the game starts
void UStaminaComponent::BeginPlay()
{
	Super::BeginPlay();
}


void UStaminaComponent::DrainStamina(float DeltaTime)
{
	if (CurrentStamina)
	{
		CurrentStamina -= DrainRate * DeltaTime;
		CurrentStamina = FMath::Clamp(CurrentStamina, 0.0f, MaxStamina);
	}
}

void UStaminaComponent::RecoverStamina(float DeltaTime)
{
	if (CurrentStamina < MaxStamina)
	{
		CurrentStamina += RecoveryRate * DeltaTime;
		CurrentStamina = FMath::Clamp(CurrentStamina, 0.0f, MaxStamina);
	}
}

float UStaminaComponent::GetStaminaPercentage() const
{
	return CurrentStamina / MaxStamina;
}

bool UStaminaComponent::HasEnoughStamina(float Cost) const
{
	return CurrentStamina >= Cost;
}

void UStaminaComponent::SpendStamina(float Cost)
{
	CurrentStamina = FMath::Clamp(CurrentStamina - Cost, 0.0f, MaxStamina);
}

