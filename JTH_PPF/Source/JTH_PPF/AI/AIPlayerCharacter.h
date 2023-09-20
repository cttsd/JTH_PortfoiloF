// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Global/GlobalCharacter.h"
#include "AIEnum.h"
#include <Global/Data/PlayerCharacterData.h>
#include "AIPlayerCharacter.generated.h"


/**
 *
 */
UCLASS()
class JTH_PPF_API AAIPlayerCharacter : public AGlobalCharacter
{
	GENERATED_BODY()


public:
	AAIPlayerCharacter();

	UPROPERTY(Category = "CharacterData", EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	FName AttDataName = "NONE";

	struct FPlayerCharacterData* CurPlayerCharacterData;

	int CharacterATT = 0;

	float CharacterHP = 0;
	float CharacterMAXHP = 0;

	void AttackAction();
	void JumpAction();

	void MoveRight(float Val);
	void MoveForward(float Val);
	void TurnAtRate(float Rate);
	void LookUpAtRate(float Rate);
	
	/*class AGlobalCharacter* GetGlobalCharacter()
	{
		return GlobalCharacter;
	}

	void PlayerHPCheck();
	
	int PlayerHP = 0;*/

protected:
	void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void BeginPlay() override;



private:
	//virtual void Tick(float Delta) override;
	//virtual void Tick(float _Delta) override;

	UPROPERTY(Category = "Components", EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
		class USpringArmComponent* SpringArmComponent;

	UPROPERTY(Category = "Components", EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
		class UCameraComponent* CameraComponent;

	//void Tick(float _Delta) override;

	UPROPERTY(Category = "Components", EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
		TMap<AIAniState, class UAnimMontage*> MapAnimation;

	UFUNCTION()
		void MontageEnd(UAnimMontage* Anim, bool _Inter);

	UFUNCTION()
		void AnimNotifyBegin(FName NotifyName, const FBranchingPointNotifyPayload& BranchingPointPayload);

		//class AGlobalCharacter* GlobalCharacter = nullptr;
};
