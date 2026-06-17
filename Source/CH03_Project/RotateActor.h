// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RotateActor.generated.h"

UCLASS(Blueprintable)
class CH03_PROJECT_API ARotateActor : public AActor
{
	GENERATED_BODY()

public:
	ARotateActor();
	
	void SetProperties(const float InRotateSpeed, const float InTeleportTime)
	{
		this->RotateSpeed = InRotateSpeed;
		this->TeleportTime = InTeleportTime;
	}

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Custom|Components")
	USceneComponent* SceneRoot;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom|Components")
	UStaticMeshComponent* StaticMeshComponent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Custom|Properties")
	float RotateSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Custom|Properties")
	float TeleportTime;

	virtual void BeginPlay() override;
	// virtual void Tick(float DeltaTime) override;

private:
	FTimerHandle FunctionHandle;
	void Function();

	FTimerHandle TeleportHandle;
	void Teleport();
};
