// Fill out your copyright notice in the Description page of Project Settings.


#include "Global/GlobalCharacter.h"
#include "Components/CapsuleComponent.h"
#include "Global/GlobalGameInstance.h"


// Sets default values
AGlobalCharacter::AGlobalCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AGlobalCharacter::BeginPlay()
{
	
	Super::BeginPlay();
	/*
	UGlobalGameInstance* Inst = GetWorld()->GetGameInstance<UGlobalGameInstance>();
	if (nullptr != Inst)
	{
		CurPlayerCharacterData = Inst->GetPlayerCharacterData(AttDataName);
	}
	characterATT = CurPlayerCharacterData->ATT;
	*/
	GlobalAnimInstance = Cast<UGlobalAnimInstance>(GetMesh()->GetAnimInstance());

	GlobalAnimInstance->AllAnimations = AllAnimations;

	GetCapsuleComponent()->OnComponentBeginOverlap.AddDynamic(this, &AGlobalCharacter::OverLap);
}

// Called every frame
void AGlobalCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


}

// Called to bind functionality to input
void AGlobalCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}


void AGlobalCharacter::OverLap(UPrimitiveComponent* OverlappedComponent,
	AActor* OtherActor,
	UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex,
	bool bFromSweep, const FHitResult& SweepResult)
{
	// ���� HP�� ������� �ִٸ�.
	// ���⼭ ��� 
	// ���� ������ ������ Hp�� ���̶�� �Ҽ� ������
	// �������ϱ�?
	// �Ѿ��ϱ�?
	// Tag

	if (true == OtherComp->ComponentHasTag(TEXT("Damage")))
	{
		
		
		//���� �ִ� Att�� ���� ���ݷ��� �ƴ� ���� �޴� �������� ���ϴ� ����
		HP -= Att;
		if (0 >= HP)
		{
			HP = 0;
			// 0 ������ �������� �ʰ� ����
		}
		
		
		
		/*
		int ATT = 0;
		UGlobalGameInstance* Inst = GetWorld()->GetGameInstance<UGlobalGameInstance>();
		//APortfolio_Tile* Tile = NewObject<APortfolio_Tile>();

		ATT = Inst->SetGameData();
		
		// ��밡 ������� �����ٸ� ��� �˾ƿð��̳�?

		HP -= ATT;
		if (0 >= HP)
		{
			HP = 0;
			// 0 ������ �������� �ʰ� ����
		}
		//Damage(OtherActor);
		*/
	}
	
	if (true == OtherComp->ComponentHasTag(TEXT("HeartPostion")))
	{
		HP += 20;
		//���Ͱ� �׾��� �� ����ϴ� ��Ʈ��� �������� ������ ü���� 20 ȸ����
		if (HP >= 100)
		{
			HP = 100;
			// ��� ���Ͽ��� ü���� 100���� �߱� ������ �� �̻����� ü���� �ö��� ���� 100���� ����
		}
	}

}