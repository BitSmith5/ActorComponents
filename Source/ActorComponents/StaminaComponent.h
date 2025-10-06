// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "StaminaComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ACTORCOMPONENTS_API UStaminaComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UStaminaComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stamina")
	float MaxStamina;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stamina")
	float CurrentStamina;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stamina")
	float RecoveryRate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stamina")
	float DrainRate;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Stamina")
	bool bIsSprinting;

	UFUNCTION(BlueprintCallable, Category = "Stamina")
	void DrainStamina(float DeltaTime);

	UFUNCTION(BlueprintCallable, Category = "Stamina")
	void RecoverStamina(float DeltaTime);

	UFUNCTION(BlueprintCallable, Category = "Stamina")
	float GetStaminaPercentage() const;

	UFUNCTION(BlueprintCallable, Category = "Stamina")
	bool HasEnoughStamina(float Cost) const;

	UFUNCTION(BlueprintCallable, Category = "Stamina")
	void SpendStamina(float Cost);

		
};
