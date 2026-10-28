// hzxynox


#include "Fudnesia/Public/Characters/Player/FunesiaPlayerCharacter.h"

#include "EnhancedInputComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Kismet/KismetMathLibrary.h"


AFunesiaPlayerCharacter::AFunesiaPlayerCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
	
	Comp_SpringArm = CreateDefaultSubobject<USpringArmComponent>("SpringArm");
	Comp_Camera = CreateDefaultSubobject<UCameraComponent>("Camera");
	
	GetCharacterMovement()->bOrientRotationToMovement = true;
	
	Comp_SpringArm->SetupAttachment(GetRootComponent());
	
	Comp_Camera->SetupAttachment(Comp_SpringArm);
}

void AFunesiaPlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void AFunesiaPlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
}

void AFunesiaPlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	
	if (UEnhancedInputComponent* EIC = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		EIC->BindAction(IA_Move, ETriggerEvent::Triggered, this, &AFunesiaPlayerCharacter::Input_Move);
	}
}

void AFunesiaPlayerCharacter::Input_Move(const FInputActionValue& InputValue)
{
	FVector2D InputVector = InputValue.Get<FVector2D>();
	
	const auto FwdRotationValue = FRotator(0.f, GetControlRotation().Yaw, 0.f);
	const auto RgtRotationValue = FRotator(0.f, GetControlRotation().Yaw, GetControlRotation().Roll);
	
	const auto ForwardDirection = UKismetMathLibrary::GetForwardVector(FwdRotationValue);
	AddMovementInput(ForwardDirection, InputVector.X);
	
	const auto RightDirection = UKismetMathLibrary::GetRightVector(RgtRotationValue);
	AddMovementInput(RightDirection, InputVector.Y);
}
