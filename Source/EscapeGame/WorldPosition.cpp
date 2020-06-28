// Copyright James Ou 2020


#include "WorldPosition.h"
#include "GameFramework/Actor.h"

// Sets default values for this component's properties
UWorldPosition::UWorldPosition()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UWorldPosition::BeginPlay()
{
	Super::BeginPlay();

/* 	FString Log = TEXT("Hello!");
	FString* PrtLog = &Log;

	Log.Len();
	PrtLog->Len();

	UE_LOG(LogTemp, Warning, TEXT("%s"), **PrtLog); */

	FString Name = GetOwner()->GetName();
	UE_LOG(LogTemp, Warning, TEXT("%s"), *Name);
	FString ObjectPosition = GetOwner()->GetActorLocation().ToCompactString();
	UE_LOG(LogTemp, Warning, TEXT("%s"), *ObjectPosition);
	
}


// Called every frame
void UWorldPosition::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

