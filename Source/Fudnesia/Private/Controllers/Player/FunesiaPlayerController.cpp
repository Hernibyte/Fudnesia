// hzxynox


#include "Fudnesia/Public/Controllers/Player/FunesiaPlayerController.h"

#include "EnhancedInputSubsystems.h"

void AFunesiaPlayerController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
	
	if (ULocalPlayer* LocalPlayer = Cast<ULocalPlayer>(Player))
	{
		if (UEnhancedInputLocalPlayerSubsystem* InputSystem = LocalPlayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>())
		{
			if (!IMC_Default.IsNull())
			{
				InputSystem->AddMappingContext(IMC_Default.LoadSynchronous(), IMC_Default_Priority);
			}
		}
	}
}
