// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTT_RandomLocation.generated.h"

/**
 * *
 */
UCLASS()
class AURA_API UBTT_RandomLocation : public UBTTaskNode
{
	GENERATED_BODY()
	
public:
	UBTT_RandomLocation();

protected:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

private:
	TArray<AActor*> TargetPoints;
};
