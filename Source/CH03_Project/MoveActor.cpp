// Fill out your copyright notice in the Description page of Project Settings.


#include "MoveActor.h"

// Sets default values
AMoveActor::AMoveActor()
{
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
	StaticMeshComponent->SetupAttachment(SceneRoot);

	PrimaryActorTick.bCanEverTick = true;

	MoveSpeed = 100.0f;
	MaxRange = 100.0f;
}

void AMoveActor::BeginPlay()
{
	Super::BeginPlay();

	StartLocation = GetActorLocation();
	MoveDirect = 1.0f;

	GetWorld()->GetTimerManager().SetTimer(
		FunctionHandle,
		this,
		&AMoveActor::Function,
		0.02f,
		true
	);
	
	if (TeleportTime <= 0.0f)
		return;

	GetWorld()->GetTimerManager().SetTimer(
		TeleportHandle,
		this,
		&AMoveActor::Teleport,
		TeleportTime,
		true
	);
}

// void AMoveActor::Tick(float DeltaTime)
// {
// 	Super::Tick(DeltaTime);
//
// 	if (!FMath::IsNearlyZero(MoveSpeed))
// 	{
// 		const FVector MoveOffset = FVector::UpVector * MoveSpeed * DeltaTime * MoveDirect;
// 		FVector NewLocation = GetActorLocation() + MoveOffset;
//
// 		const float distance = FVector::Distance(StartLocation, NewLocation);
// 		if (distance > MaxRange)
// 		{
// 			MoveDirect *= -1.0f;
// 			NewLocation = GetActorLocation() + MoveOffset * -1.0f;
// 		}
//
// 		SetActorLocation(NewLocation);
// 	}
// }

void AMoveActor::Function()
{
	if (!FMath::IsNearlyZero(MoveSpeed))
	{
		const FVector MoveOffset = FVector::UpVector * MoveSpeed * MoveDirect * 0.02f;
		FVector NewLocation = GetActorLocation() + MoveOffset;

		const float distance = FVector::Distance(StartLocation, NewLocation);
		if (distance > MaxRange)
		{
			MoveDirect *= -1.0f;
			NewLocation = GetActorLocation() + MoveOffset * -1.0f;
		}

		SetActorLocation(NewLocation);
	}
}

void AMoveActor::Teleport()
{
	const FVector NewLocation = FVector(
		FMath::RandRange(-1800.0f, 400.0f),
		FMath::RandRange(-800.0f, 1400.0f),
		FMath::RandRange(200.0f, 800.0f)
	);

	SetActorLocation(NewLocation);

	StartLocation = GetActorLocation();
	MoveDirect = 1.0f;
}
