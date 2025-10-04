// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "FItemStruct.h"
#include "InventoryComponent.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ACTORCOMPONENTS_API UInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UInventoryComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
	int32 Capacity;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Inventory")
	TArray<FItemStruct> Items;

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	bool AddItem(const FItemStruct& Item);

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	bool RemoveItemByName(FName Item, int32 Quantity);

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	bool HasItem(FName Item) const;
};
