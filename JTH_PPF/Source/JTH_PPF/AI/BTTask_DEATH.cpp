// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/BTTask_DEATH.h"

// 1. 몬스터 죽는 애니메이션을 끝나면 화면에서 완전히 사라져야 합니다.

UBTTask_DEATH::UBTTask_DEATH()
{
	bNotifyTick = true;
	bNotifyTaskFinished = true;
}


EBTNodeResult::Type UBTTask_DEATH::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	GetGlobalCharacter(OwnerComp)->SetAniState(AIState::DEATH);
	return EBTNodeResult::Type::InProgress;
}


void UBTTask_DEATH::TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DelataSeconds)
{
	Super::TickTask(OwnerComp, NodeMemory, DelataSeconds);

	UAnimMontage* Montage = GetGlobalCharacter(OwnerComp)->GetAnimMontage(UBTTask_AIBase::GetAiState(OwnerComp));
	float Time = Montage->CalculateSequenceLength();
	if (Time <= GetStateTime(OwnerComp))
	{
		GetGlobalCharacter(OwnerComp)->Destroy();
	}
}