// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FPSPK_IInteract.h"
#include "Switch.generated.h"

UCLASS()
class FPSPK_API ASwitch : public AActor, public IFPSPK_IInteract
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ASwitch();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void Interact_Implementation() override;

	// Adding something similar to the unreal "FlipFlop"
	UPROPERTY(EditAnywhere)
	UMaterialInterface* Material1;
	UPROPERTY(EditAnywhere)
	UMaterialInterface*  Material2;

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* MeshComponent;
	
	bool bIsFlipFlopActivated = false;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
};
