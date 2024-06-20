// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameInstance.h"

UMyGameInstance::UMyGameInstance() {


	// Actor Blueprinter
	static ConstructorHelpers::FClassFinder<AActor> ActorBPClass(TEXT("Blueprint'/Game/Map/BP_MyActor'"));

	if (ActorBPClass.Succeeded()) {
		BP_MyActorClass = ActorBPClass.Class;

		UE_LOG(LogTemp, Warning, TEXT("ActorBPClass"));
	}

}

void UMyGameInstance::Init()
{
	Super::Init();
	ControlBP_MyActor();
}

void UMyGameInstance::ControlBP_MyActor()
{
	if (BP_MyActorClass != nullptr && GetWorld() != nullptr)
	{
		FActorSpawnParameters SpawnParams;
		SpawnParams.Owner = nullptr;
		SpawnParams.Instigator = nullptr;

		FVector vector;
		vector = { 5.0f,10.0f,7.0f };

		FRotator rotator;
		rotator.Pitch = 15;
		rotator.Yaw = 5;
		rotator.Roll = 15;
		spawnActor = GetWorld()->SpawnActor<AActor>(BP_MyActorClass, vector,
			rotator, SpawnParams);

		if (spawnActor) {
			UE_LOG(LogTemp, Warning, TEXT("spawnActor"));
		}
	}
}

