// hzxynox

#pragma once

#include "CoreMinimal.h"
#include "InputMappingContext.h"
#include "Fudnesia/Public/Controllers/FunesiaBaseController.h"
#include "FunesiaPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class FUDNESIA_API AFunesiaPlayerController : public AFunesiaBaseController
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, Category="Input")
	TSoftObjectPtr<UInputMappingContext> IMC_Default;
	UPROPERTY(EditAnywhere, Category="Input")
	int32 IMC_Default_Priority = 0;
	
protected:
	virtual void OnPossess(APawn* InPawn) override;
};
