// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/BTT_CustomLocation.h"

#include "BehaviorTree/BlackBoardComponent.h"
#include "Kismet/GamePlayStatics.h"
#include "Engine/TargetPoint.h"

UBTT_CustomLocation::UBTT_CustomLocation()
{
	NodeName = "Get Custom Location";
}

EBTNodeResult::Type UBTT_CustomLocation::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8 NodeMemory)
{
    if (TargetPoints.Num() == 0)
    {
        UGameplayStatics::GetAllActorsOfClass(GetWorld(), ATargetPoint::StaticClass(), TargetPoints);
    }

    if (TargetPoints.Num() == 0)
    {
        return EBTNodeResult::Failed;
    }

    // 랜덤한 TargetPoint 선택
    int32 RandomIndex = FMath::RandRange(0, TargetPoints.Num() - 1);
    AActor* RandomTargetPoint = TargetPoints[RandomIndex];

    // Blackboard에 위치 설정
    if (RandomTargetPoint)
    {
        FVector TargetLocation = RandomTargetPoint->GetActorLocation();
        OwnerComp.GetBlackboardComponent()->SetValueAsVector(FName("TargetLocation"), TargetLocation);
        return EBTNodeResult::Succeeded;
    }

    return EBTNodeResult::Failed;
}