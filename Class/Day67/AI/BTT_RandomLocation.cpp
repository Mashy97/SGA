// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/BTT_RandomLocation.h"

#include "BehaviorTree/BlackBoardComponent.h"
#include "Kismet/GamePlayStatics.h"
#include "Engine/TargetPoint.h"

UBTT_RandomLocation::UBTT_RandomLocation()
{
	NodeName = "Get Random Location";
}

EBTNodeResult::Type UBTT_RandomLocation::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{

	if (TargetPoints.Num() == 0) {
		// GetAllActorOfClass - TargetPoints¿¡ Data ÀÔ·Â
		UGameplayStatics::GetAllActorsOfClass(GetWorld(), ATargetPoint::StaticClass(), TargetPoints);
	}

	if (TargetPoints.Num() == 0) {
		return EBTNodeResult::Failed;
	}

	int32 RandomIndex = FMath::RandRange(0, TargetPoints.Num() - 1);
	AActor* RandomTargetPoint = TargetPoints[RandomIndex];

	if (RandomTargetPoint) {
		FVector TargetLocation = RandomTargetPoint->GetActorLocation();

		OwnerComp.GetBlackboardComponent()->SetValueAsVector(FName("TargetLocation"), TargetLocation);
		return EBTNodeResult::Succeeded;
	}

	return EBTNodeResult::Failed;
}