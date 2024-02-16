// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "ShooterAiController.generated.h"

/**
 * 
 */
UCLASS()
class SIMPLESHOOTER_API AShooterAiController : public AAIController
{
	GENERATED_BODY()
	
    public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	protected:
	virtual void BeginPlay() override;
		
	public:
	UPROPERTY(EditAnywhere)
	class UBehaviorTree* AIBehavior;
	// float AcceptanceRadius = 200;
	bool IsDead() const;
};
