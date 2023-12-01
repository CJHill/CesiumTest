// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameFramework/PlayerInput.h"
#include "Components/InputComponent.h"
#include "CesiumGeoreference.h"
#include <glm/vec3.hpp>
#include "CesiumGeospatial/Ellipsoid.h"
#include "CesiumGeospatial/Cartographic.h"
#include "UsefulActor.generated.h"

UCLASS()
class CESIUMTEST_API AUsefulActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AUsefulActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere, Category = "ActorSpawning")
	ACesiumGeoreference* Georeference;
	UPROPERTY()
	USceneComponent* Root;
	class UStaticMeshComponent* StaticMesh;
	
private:
	void SetupInputComponent();
	FVector TransformedUnits;
	/*Blueprint Reference of UsefulActor class*/
	UPROPERTY(EditDefaultsOnly, Category = "ActorSpawning")
	TSubclassOf<AUsefulActor> UsefulActorBP;

	UPROPERTY(EditAnywhere, Category = "ActorSpawning")
	float TimeToSpawn = 2.f;

	/*Spawns the UsefulActor Blueprint*/
	UFUNCTION()
	void SpawnUsefulActor();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
