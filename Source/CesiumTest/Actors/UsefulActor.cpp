// Fill out your copyright notice in the Description page of Project Settings.


#include "UsefulActor.h"


// Sets default values
AUsefulActor::AUsefulActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Root = CreateDefaultSubobject<USceneComponent>("Root");
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>("Static Mesh Component ");
    StaticMesh->SetupAttachment(Root);
	Georeference = CreateDefaultSubobject<ACesiumGeoreference>("Georeference");
	this->Georeference = ACesiumGeoreference::GetDefaultGeoreference(this);
	
}

// Called when the game starts or when spawned
void AUsefulActor::BeginPlay()
{
	Super::BeginPlay();

    FTimerHandle OutHandle;
    //Will call SpawnUsefulActor after the specified time
    GetWorld()->GetTimerManager().SetTimer(OutHandle, this, &AUsefulActor::SpawnUsefulActor, TimeToSpawn);
	//Georeference->TransformLongitudeLatitudeHeightPositionToUnreal()
}

void AUsefulActor::SetupInputComponent()
{

}

void AUsefulActor::SpawnUsefulActor()
{
	FVector WorldLocation;
	double Longitude = -87.6298;
	double Latitude = 41.8781;
	double Height = 1000;
	WorldLocation.X = Longitude;
	WorldLocation.Y = Latitude;
	WorldLocation.Z = Height;
	

}

// Called every frame
void AUsefulActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

