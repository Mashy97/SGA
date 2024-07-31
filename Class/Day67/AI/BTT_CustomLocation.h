// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTT_CustomLocation.generated.h"

/**
 * 
 */
UCLASS()
class AURA_API UBTT_CustomLocation : public UBTTaskNode
{
	GENERATED_BODY()

public:
	UBTT_CustomLocation();

protected:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8 NodeMemory);

private:
	TArray<AActor*> TargetPoints;
};
