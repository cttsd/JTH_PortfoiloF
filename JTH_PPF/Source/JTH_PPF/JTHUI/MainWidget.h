// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AI/AIPlayerCharacter.h"
#include "Global/GlobalCharacter.h"
#include "MainWidget.generated.h"

/**
 * 
 */
UCLASS()
class JTH_PPF_API UMainWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	void PlayerHP();

	class AAIPlayerCharacter* CurPlayerCharacter;

	int GetHP()
	{
		return PlayHP;
	}

	int GetMAXHP()
	{
		return PlayMAXHP;
	}
	
	
	UFUNCTION(BlueprintCallable)
	bool CheckAllWidGetHidden();

	UFUNCTION(BlueprintCallable)
	void SetOptionOnOffSwitch()
	{
		OptionOnOff = OptionOnOff == ESlateVisibility::Hidden ? ESlateVisibility::Visible : ESlateVisibility::Hidden;
	}
	/*
	void SetStatusWindowOnOffSwitch()
	{
		StatusWindowOnOff = StatusWindowOnOff == ESlateVisibility::Hidden ? ESlateVisibility::Visible : ESlateVisibility::Hidden;
	}*/

	void SetInventoryOnOffSwitch()
	{
		InventoryOnOff = InventoryOnOff == ESlateVisibility::Hidden ? ESlateVisibility::Visible : ESlateVisibility::Hidden;
	}
	
	/*UFUNCTION(BlueprintCallable)
	void PlayerHPe();
	
	class AAIPlayerCharacter* GetAIPlayerCharacter()
	{
		AIPlayerCharacter;
	}*/

protected:
	
	void NativeConstruct() override;
	void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;
	

private:
	
	UPROPERTY(Category = "UIOnOff", EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	ESlateVisibility InventoryOnOff = ESlateVisibility::Hidden;

	/*UPROPERTY(Category = "UIOnOff", EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	ESlateVisibility StatusWindowOnOff = ESlateVisibility::Hidden;*/

	UPROPERTY(Category = "UIOnOff", EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	ESlateVisibility OptionOnOff = ESlateVisibility::Hidden;
	
	class UInventoryUserWidget* Inven;


	UPROPERTY(Category = "CharacterHPM", EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	float PlayHP = 0;
	
	UPROPERTY(Category = "CharacterHPM", EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	float PlayMAXHP = 0;
    /*
	class AAIPlayerCharacter* AIPlayerCharacter = nullptr;*/
	
	UPROPERTY()
	TArray<UUserWidget*> AllWidGet;

	UPROPERTY(Category = "Effect", EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	bool AllHidden = true;
	
};
