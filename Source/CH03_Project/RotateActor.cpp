// Fill out your copyright notice in the Description page of Project Settings.


#include "RotateActor.h"

// Sets default values
ARotateActor::ARotateActor()
{
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
	StaticMeshComponent->SetupAttachment(SceneRoot);

	PrimaryActorTick.bCanEverTick = true;

	RotateSpeed = 50.0f;
}

void ARotateActor::BeginPlay()
{
	Super::BeginPlay();

	GetWorld()->GetTimerManager().SetTimer(
		FunctionHandle,
		this,
		&ARotateActor::Function,
		0.02f,
		true
	);

	if (TeleportTime <= 0.0f)
		return;

	GetWorld()->GetTimerManager().SetTimer(
		TeleportHandle,
		this,
		&ARotateActor::Teleport,
		TeleportTime,
		true
	);
}

// void ARotateActor::Tick(float DeltaTime)
// {
// 	Super::Tick(DeltaTime);
//
// 	if (!FMath::IsNearlyZero(RotateSpeed))
// 	{
// 		AddActorLocalRotation(FRotator(0.0f, RotateSpeed * DeltaTime, 0.0f));	
// 	}
// }

void ARotateActor::Function()
{
	if (!FMath::IsNearlyZero(RotateSpeed))
	{
		AddActorLocalRotation(FRotator(0.0f, RotateSpeed * 0.02f, 0.0f));
	}
}

void ARotateActor::Teleport()
{
	const FVector NewLocation = FVector(
		FMath::RandRange(-1800.0f, 400.0f),
		FMath::RandRange(-800.0f, 1400.0f),
		FMath::RandRange(200.0f, 800.0f)
	);

	SetActorLocation(NewLocation);
}
