// Fill out your copyright notice in the Description page of Project Settings.

#include "ShooterAiController.h"
#include "Kismet/GameplayStatics.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "ShooterCharacter.h"

void AShooterAiController::BeginPlay()
{
    Super::BeginPlay();
    if(AIBehavior!=nullptr){
        RunBehaviorTree(AIBehavior);
             APawn *PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);

        GetBlackboardComponent()->SetValueAsVector(TEXT("PlayerLocation"), PlayerPawn->GetActorLocation());
        GetBlackboardComponent()->SetValueAsVector(TEXT("StartLocation"), GetPawn()->GetActorLocation());

    }
}


void AShooterAiController::Tick(float DeltaTime)

{
    Super::Tick(DeltaTime);
    // APawn *PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);

    // if(LineOfSightTo(PlayerPawn))
    // {
    // //     SetFocus(PlayerPawn);
    // //     MoveToActor(PlayerPawn, AcceptanceRadius);
    //     GetBlackboardComponent()->SetValueAsVector(TEXT("PlayerLocation"), PlayerPawn->GetActorLocation());
    //     GetBlackboardComponent()->SetValueAsVector(TEXT("LastKnownPlayerLocation"), GetPawn()->GetActorLocation());
    // }
    // else
    // {
    //    GetBlackboardComponent()->ClearValue(TEXT("PlayerLocation"));
    // //     ClearFocus(EAIFocusPriority::Gameplay);
    // //     StopMovement();
    // }
}

bool AShooterAiController::IsDead() const
{
    AShooterCharacter* ControlledCharacter = Cast<AShooterCharacter>(GetPawn());
    if (ControlledCharacter != nullptr)
    {
        return ControlledCharacter->IsDead();
    }

    return true;
}
