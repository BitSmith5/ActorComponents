// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryComponent.h"

// Sets default values for this component's properties
UInventoryComponent::UInventoryComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


// Called when the game starts
void UInventoryComponent::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Warning, TEXT("Inventory capacity: %d"), Capacity);
	UE_LOG(LogTemp, Warning, TEXT("Items before adding: %d"), Items.Num());
	
}

bool UInventoryComponent::AddItem(const FItemStruct& Item)
{
	UE_LOG(LogTemp, Warning, TEXT("AddItem called: %s"), *Item.Name.ToString());
	UE_LOG(LogTemp, Warning, TEXT("Capacity = %d"), Capacity);
	UE_LOG(LogTemp, Warning, TEXT("Items.Num() = %d"), Items.Num());

	if (Items.Num() >= Capacity)
	{
		UE_LOG(LogTemp, Warning, TEXT("Inventory is full! Cannot add item: %s"), *Item.Name.ToString());
		return false;
	}

	for (FItemStruct& ExistingItem : Items)
	{
		if (ExistingItem.Name == Item.Name)
		{
			ExistingItem.Quantity += Item.Quantity;
			UE_LOG(LogTemp, Log, TEXT("Increased quantity of item: %s to %d"), *Item.Name.ToString(), ExistingItem.Quantity);
			return true;
		}
	}
	Items.Add(Item);
	UE_LOG(LogTemp, Log, TEXT("Item added: %s"), *Item.Name.ToString());
	return true;
}

bool UInventoryComponent::RemoveItemByName(FName Item, int32 Quantity)
{

	for (int i = 0; i < Items.Num(); i++)
	{
		if (Items[i].Name == Item)
		{
			if (Items[i].Quantity > Quantity)
			{
				Items[i].Quantity -= Quantity;
				UE_LOG(LogTemp, Log, TEXT("Decreased quantity of item: %s to %d"), *Item.ToString(), Items[i].Quantity);
				return true;
			}
			else if (Items[i].Quantity == Quantity)
			{
				Items.RemoveAt(i);
				UE_LOG(LogTemp, Log, TEXT("Item removed: %s"), *Item.ToString());
				return true;
			}
			else
			{
				UE_LOG(LogTemp, Warning, TEXT("Not enough quantity to remove for item: %s"), *Item.ToString());
				return false;
			}
		}
	}

	UE_LOG(LogTemp, Warning, TEXT("Item not found: %s"), *Item.ToString());
	return false;
}

bool UInventoryComponent::HasItem(FName Item) const
{
	for (const FItemStruct& ExistingItem : Items)
	{
		if (ExistingItem.Name == Item)
		{
			return true;
		}
	}
	return false;
}

