#pragma once

#include "CoreMinimal.h"

// �ִϸ��̼ǿ� �����Ұų�
// ĳ���Ϳ� ������ �ų�?

// ���Ϳ� �÷��̾ ���� ��� �ִϸ��̼� ���¿� ���ؼ� ������ �����ϳĸ� �����غ���
// �Ұ����ϴٸ� Enum�� ����� �ȵȴ�.


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

