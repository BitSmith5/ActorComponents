// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "StreetLightActor.generated.h"

UCLASS()
class ACTORCOMPONENTS_API AStreetLightActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AStreetLightActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Light")
	void ToggleLight();

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Light")
	UStaticMeshComponent* LightMesh;

	UPROPERTY()
	UMaterialInstanceDynamic* bulbMaterial;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Light")
	float bulbIntensity = 20.0f;

	bool bIsLightOn;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
