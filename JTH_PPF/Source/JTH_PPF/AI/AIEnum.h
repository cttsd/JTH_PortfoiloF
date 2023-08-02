#pragma once

#include "CoreMinimal.h"

// 애니메이션에 집중할거냐
// 캐릭터에 집중할 거냐?

// 몬스터와 플레이어가 정말 모든 애니메이션 상태에 대해서 공유가 가능하냐를 생각해보고
// 불가능하다면 Enum은 사용이 안된다.


UENUM(BlueprintType)
enum class AIAniState : uint8
{
	None UMETA(DisplayName = "AINone"),
	Idle UMETA(DisplayName = "AIIDLE"),
	LeftMove UMETA(DisplayName = "AILFTM"),
	RightMove UMETA(DisplayName = "AIRGTM"),
	ForwardMove UMETA(DisplayName = "AIFWDM"),
	BackwardMove UMETA(DisplayName = "AIBKWM"),
	Jump UMETA(DisplayName = "AIJUMP"),
	Attack UMETA(DisplayName = "AIATTACK"),
};

