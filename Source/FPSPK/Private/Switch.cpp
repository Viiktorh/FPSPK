// Fill out your copyright notice in the Description page of Project Settings.

#include "Switch.h"

#include "EngineUtils.h"

// Sets default values
ASwitch::ASwitch()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// FlipFlopping between materials
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	RootComponent = MeshComponent;
}

// Called when the game starts or when spawned
void ASwitch::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ASwitch::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ASwitch::Interact_Implementation()
{
	GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Blue, TEXT("INTERACTED!!!"));
	FVector MoveCube = FVector(0, 100, 0);
	SetActorLocation(GetActorLocation() + MoveCube);

	// Adding something similar to the unreal "FlipFlop"
	bIsFlipFlopActivated = !bIsFlipFlopActivated;

	if (bIsFlipFlopActivated)
	{
		MeshComponent->SetMaterial(0, Material1);
	}
	else if (!bIsFlipFlopActivated)
	{
		MeshComponent->SetMaterial(0, Material2);
	}
}