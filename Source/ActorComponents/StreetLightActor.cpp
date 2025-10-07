// Fill out your copyright notice in the Description page of Project Settings.


#include "StreetLightActor.h"

// Sets default values
AStreetLightActor::AStreetLightActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	LightMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("LightMesh"));
	LightMesh->SetupAttachment(RootComponent);

	//bulbMaterial = MaterialInstanceDynamic
}

// Called when the game starts or when spawned
void AStreetLightActor::BeginPlay()
{
	Super::BeginPlay();
	
}

void AStreetLightActor::ToggleLight()
{
	if (!LightMesh) return;

	if (!bulbMaterial)
	{
		bulbMaterial = LightMesh->CreateAndSetMaterialInstanceDynamic(1);
	}

	bIsLightOn = !bIsLightOn;

	bulbMaterial->SetScalarParameterValue(TEXT("EmissiveStrength"), bIsLightOn ? bulbIntensity: 0.0f);
}

// Called every frame
void AStreetLightActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

