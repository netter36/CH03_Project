// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MoveActor.generated.h"

UCLASS(Blueprintable)
class CH03_PROJECT_API AMoveActor : public AActor
{
	GENERATED_BODY()

public:
	AMoveActor();

	void SetProperties(const float InMoveSpeed, const float InMaxRange, const float InTeleportTime)
	{
		this->MoveSpeed = InMoveSpeed;
		this->MaxRange = InMaxRange;
		this->TeleportTime = InTeleportTime;
	}

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Custom|Components")
	USceneComponent* SceneRoot;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom|Components")
	UStaticMeshComponent* StaticMeshComponent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Custom|Properties")
	float MoveSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Custom|Properties")
	float MaxRange;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Custom|Properties")
	float TeleportTime;

	virtual void BeginPlay() override;
	// virtual void Tick(float DeltaTime) override;

private:
	FVector StartLocation;
	float MoveDirect;

	FTimerHandle FunctionHandle;
	void Function();

	FTimerHandle TeleportHandle;
	void Teleport();
};
