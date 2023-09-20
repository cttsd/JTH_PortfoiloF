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
	// 만약 HP를 깎는일이 있다면.
	// 여기서 깍고 
	// 지금 당장은 무조건 Hp가 깍이라고 할수 있지만
	// 아이템일까?
	// 총알일까?
	// Tag

	if (true == OtherComp->ComponentHasTag(TEXT("Damage")))
	{
		
		
		//여기 있는 Att은 나의 공격력이 아닌 내가 받는 데미지를 말하는 거임
		HP -= Att;
		if (0 >= HP)
		{
			HP = 0;
			// 0 밑으로 떨어지지 않게 고정
		}
		
		
		
		/*
		int ATT = 0;
		UGlobalGameInstance* Inst = GetWorld()->GetGameInstance<UGlobalGameInstance>();
		//APortfolio_Tile* Tile = NewObject<APortfolio_Tile>();

		ATT = Inst->SetGameData();
		
		// 상대가 대미지를 가졌다면 어떻게 알아올것이냐?

		HP -= ATT;
		if (0 >= HP)
		{
			HP = 0;
			// 0 밑으로 떨어지지 않게 고정
		}
		//Damage(OtherActor);
		*/
	}
	
	if (true == OtherComp->ComponentHasTag(TEXT("HeartPostion")))
	{
		HP += 20;
		//몬스터가 죽었을 때 드랍하는 하트모양 아이템을 먹으면 체력이 20 회복됨
		if (HP >= 100)
		{
			HP = 100;
			// 헤더 파일에서 체력을 100으로 했기 때문에 그 이상으로 체력이 올라갔을 때는 100으로 고정
		}
	}

}