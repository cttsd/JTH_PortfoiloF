// Fill out your copyright notice in the Description page of Project Settings.


#include "JTHUI/MainWidget.h"
#include "AI/AIPlayerCharacter.h"
#include "InventoryUserWidget.h"

void UMainWidget::NativeConstruct()
{
	Super::NativeConstruct();

	// Inven = Cast<UInventoryUserWidget>(GetWidgetFromName(TEXT("WBP_Inventory")));
	// Inven = Cast<UInventoryUserWidget>(GetWidgetFromName(TEXT("WBP_Status")));

	AllWidGet.Add(Cast<UUserWidget>(GetWidgetFromName(TEXT("WBP_Inventory"))));
	//AllWidGet.Add(Cast<UUserWidget>(GetWidgetFromName(TEXT("WBP_Status"))));
}

/*AAIPlayerCharacter* UMainWidget::GetAIPlayerCharacter()
{
	GetAIPlayerCharacter()->PlayerHPCheck();
}*/




void UMainWidget::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);
	
	// //GetAIPlayerCharacter()->PlayerHPCheck();
	// �⺻���� �̵��̳� �̷� �ý�����ü�� �ٸ��ٴ°��� ����ؾ� �Ѵ�.
	// Inven->SetPositionInViewport({100, 100});
	// Inven->SetAnchorsInViewport();
}

// ���⼭ �����ϴ� bool ���� ���� ���°� �ٲ���ٴ� AllHidden�� �ٲ���ٴ°��� üũ�ϴ� bool ���� �ȴ�.
bool UMainWidget::CheckAllWidGetHidden()
{
	bool AllHiddenCheck = true;

	for (size_t i = 0; i < AllWidGet.Num(); i++)
	{
		if (AllWidGet[i]->GetVisibility() == ESlateVisibility::Visible)
		{
			AllHiddenCheck = false;
		}
	}

	// false���µ� true�� �ǰ�
	// true���µ� false�� �Ǵ� ��Ȳ�� ����
	if (AllHiddenCheck != AllHidden)
	{
		AllHidden = AllHiddenCheck;
		return true;
	}

	return false;
}
