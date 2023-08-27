#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "UObject/NoExportTypes.h"
#include "PlayerCharacterData.generated.h"

/**
 *
 */
USTRUCT(BlueprintType)
struct JTH_PPF_API FPlayerCharacterData : public FTableRowBase
{
	GENERATED_BODY()

	FPlayerCharacterData() {}
	~FPlayerCharacterData() {}

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
	int HP;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
	int ATT;

	
};