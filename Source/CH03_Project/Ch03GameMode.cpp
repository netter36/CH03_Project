// Fill out your copyright notice in the Description page of Project Settings.


#include "Ch03GameMode.h"

#include "MoveActor.h"
#include "RotateActor.h"

void ACh03GameMode::BeginPlay()
{
	Super::BeginPlay();

	for (int i = 0; i < SpawnCount; ++i)
	{
		const int Random = FMath::RandRange(0, 1);

		const FVector NewLocation = FVector(
			FMath::RandRange(-1800.0f, 400.0f),
			FMath::RandRange(-800.0f, 1400.0f),
			FMath::RandRange(200.0f, 800.0f)
		);

		const FTransform SpawnTransform = FTransform(FRotator::ZeroRotator, NewLocation);

		AActor* SpawnActor = GetWorld()->SpawnActorDeferred<AActor>(
			Random == 0 ? ActorToSpawn1 : ActorToSpawn2,
			SpawnTransform
		);

		const float TeleportTime = FMath::RandRange(10.0f, 20.0f);

		if (AMoveActor* MoveActor = Cast<AMoveActor>(SpawnActor))
		{
			const float MoveSpeed = FMath::RandRange(MinMoveSpeed, MaxMoveSpeed);
			const float MaxRange = FMath::RandRange(MinMaxRange, MaxMaxRange);
			MoveActor->SetProperties(MoveSpeed, MaxRange, TeleportTime);
		}

		if (ARotateActor* RotateActor = Cast<ARotateActor>(SpawnActor))
		{
			const float RotateSpeed = FMath::RandRange(MinRotateSpeed, MaxRotateSpeed);
			RotateActor->SetProperties(RotateSpeed, TeleportTime);
		}

		SpawnActor->FinishSpawning(SpawnTransform);
	}
}
