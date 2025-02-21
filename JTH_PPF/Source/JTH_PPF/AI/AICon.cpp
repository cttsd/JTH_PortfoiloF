// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/AICon.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/BehaviorTree.h"
#include <Global/AICharacter.h>

AAICon::AAICon()
{
	BehaviorTreeComponent = CreateDefaultSubobject<UBehaviorTreeComponent>(TEXT("BehaviorTreeComponent"));

	BlackboardComponent = CreateDefaultSubobject<UBlackboardComponent>(TEXT("BlackboardComponent"));;
}

// 빙의 순간 
// 캐릭터만들어지고 이제부터 컨트롤러가 이캐릭터를 조작할것이다.
void AAICon::OnPossess(APawn* _InPawn)
{
	Super::OnPossess(_InPawn);

	if (nullptr != BehaviorTreeComponent && true == BehaviorTreeComponent->IsValidLowLevel())
	{
		AAICharacter* AIPawn = Cast<AAICharacter>(_InPawn);

		UBehaviorTree* BehaviorTree = AIPawn->GetBehaviorTree();

		if (nullptr == BehaviorTree || false == BehaviorTree->IsValidLowLevel())
		{
			UE_LOG(LogTemp, Error, TEXT("%S(%u)> if (nullptr == BehaviorTree || false == BehaviorTree->IsValidLowLevel())"), __FUNCTION__, __LINE__);
			return;
		}

		BlackboardComponent->InitializeBlackboard(*BehaviorTree->BlackboardAsset);

		BlackboardComponent->SetValueAsObject(TEXT("SelfActor"), _InPawn);

		BehaviorTreeComponent->StartTree(*BehaviorTree);
	}

	// 행동트리 에셋을 집어 넣어주고
	// BehaviorTreeComponent

	// 행동트리들이 공유할 데이터을 집어 넣어주면
	// BlackboardComponent

	// 직접 동작하라고 블루프린트나 C++ 명령을 내려야만 동작합니다.
}

