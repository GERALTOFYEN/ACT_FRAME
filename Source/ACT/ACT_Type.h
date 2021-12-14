
#include "CoreMinimal.h"
#include "ACT_Type.generated.h"

UENUM(BlueprintType)
enum class EACT_PropertyName :uint8
{
	EpropertyHP UMETA(DisplayName = "HP"),
	EpropertyEXP UMETA(DisplayName = "EXP"),
	EpropertyLevel UMETA(DisplayName = "Level")
};
USTRUCT(BlueprintType)
struct FACT_PropertyValue
{
	GENERATED_USTRUCT_BODY()
		UPROPERTY(BlueprintReadWrite,EditAnywhere)
		float min;
	   UPROPERTY(BlueprintReadWrite,EditAnywhere)
		float max;
	   UPROPERTY(BlueprintReadWrite,EditAnywhere)
		float current;
};
USTRUCT(BlueprintType)
struct FACT_InputStruct
{
	GENERATED_USTRUCT_BODY()
		UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
		; FKey key;
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
		float InputTime = .5f;
};