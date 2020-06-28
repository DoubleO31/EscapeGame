// Copyright James Ou 2020

#include "OpenDoor.h"
#include "GameFramework/Actor.h"

// Sets default values for this component's properties
UOpenDoor::UOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

// Called when the game starts
void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();
	InitialYaw = GetOwner()->GetActorRotation().Yaw;
	TargetYaw += InitialYaw;
}

// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	FRotator CurrentRotation = GetOwner()->GetActorRotation();
	UE_LOG(LogTemp, Warning, TEXT("Yaw is %f"), CurrentRotation.Yaw);
	CurrentRotation.Yaw = FMath::FInterpTo(CurrentRotation.Yaw, TargetYaw, DeltaTime, 0.8f);
	GetOwner()->SetActorRotation(CurrentRotation);

	// ...

	// float MyFloat = 90.f;

	// FRotator CurrentRotation = GetOwner()->GetActorRotation();

	// FRotator NewRotation = CurrentRotation.Add(0.f, MyFloat, 0.f);

	// GetOwner()->SetActorRotation(NewRotation);
}
