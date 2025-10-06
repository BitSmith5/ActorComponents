// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InteractableComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnInteract);


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ACTORCOMPONENTS_API UInteractableComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UInteractableComponent();

	UPROPERTY(BlueprintAssignable, Category = "Interaction")
	FOnInteract OnActivate;

	UPROPERTY(BlueprintAssignable, Category = "Interaction")
	FOnInteract OnDeactivate;

	UFUNCTION(BlueprintCallable, Category = "Interaction")
	void TurnOn();

	UFUNCTION(BlueprintCallable, Category = "Interaction")
	void TurnOff();

	UFUNCTION(BlueprintCallable, Category = "Interaction")
	bool CanInteract() const { return bCanInteract; }

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interaction")
	bool bCanInteract = true;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
