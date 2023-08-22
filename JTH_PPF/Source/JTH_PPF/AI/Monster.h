// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Global/AICharacter.h"
#include <Global/GlobalEnums.h>
#include <Global/Data/MonsterData.h>
#include "Monster.generated.h"

/**
 *
 */
UCLASS()
class JTH_PPF_API AMonster : public AAICharacter
{
	GENERATED_BODY()

public:
	AMonster();

	const struct FMonsterData* CurMonsterData;

	void BeginPlay() override;

private:
	UPROPERTY(Category = "Monster", EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
		FName DataName = "NONE";

	//UPROPERTY(Category = "Monster", EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
		//class UMiniMapComponent* MiniMap;

	UFUNCTION()
	void AnimNotifyBegin(FName NotifyName, const FBranchingPointNotifyPayload& BranchingPointPayload);
};
