// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "Ch03GameMode.generated.h"

/**
 * 
 */
UCLASS()
class CH03_PROJECT_API ACh03GameMode : public AGameMode
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom|Spawn")
	TSubclassOf<AActor> ActorToSpawn1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom|Spawn")
	TSubclassOf<AActor> ActorToSpawn2;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom|Spawn")
	int SpawnCount;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom|Move")
	float MinMoveSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom|Move")
	float MaxMoveSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom|Move")
	float MinMaxRange;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom|Move")
	float MaxMaxRange;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom|Rotate")
	float MinRotateSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom|Rotate")
	float MaxRotateSpeed;

	virtual void BeginPlay() override;
};
