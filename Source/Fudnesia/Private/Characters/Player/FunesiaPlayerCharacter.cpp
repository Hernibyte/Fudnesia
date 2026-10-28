// hzxynox


#include "Fudnesia/Public/Characters/Player/FunesiaPlayerCharacter.h"

#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Camera/CameraComponent.h"
#include "Components/FunesiaAbilitySystemComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GAS/FunesiaAttributeSet.h"
#include "Kismet/KismetMathLibrary.h"


AFunesiaPlayerCharacter::AFunesiaPlayerCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
	
	Comp_SpringArm = CreateDefaultSubobject<USpringArmComponent>("SpringArm");
	Comp_Camera = CreateDefaultSubobject<UCameraComponent>("Camera");
	Comp_AbilitySystem = CreateDefaultSubobject<UFunesiaAbilitySystemComponent>("AbilitySystemComponent");
	Comp_AttributeSet = CreateDefaultSubobject<UFunesiaAttributeSet>("AttributeSet");
	
	GetCharacterMovement()->bOrientRotationToMovement = true;
	
	Comp_SpringArm->SetupAttachment(GetRootComponent());
	Comp_Camera->SetupAttachment(Comp_SpringArm);
	
	bUseControllerRotationYaw = false;
}

void AFunesiaPlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	Comp_AbilitySystem->InitAbilityActorInfo(this, this);
}

void AFunesiaPlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
}

void AFunesiaPlayerCharacter::PawnClientRestart()
{
	Super::PawnClientRestart();
	
	if (const APlayerController* PC = Cast<APlayerController>(GetController()))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = 
			ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PC->GetLocalPlayer()))
		{
			Subsystem->ClearAllMappings();
			Subsystem->AddMappingContext(IMC_Default.LoadSynchronous(), IMC_Default_Priority);
		}
	}
}

void AFunesiaPlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	
	if (UEnhancedInputComponent* EIC = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		EIC->BindAction(IA_Move, ETriggerEvent::Triggered, this, &AFunesiaPlayerCharacter::Input_Move);
	}
}

UAbilitySystemComponent* AFunesiaPlayerCharacter::GetAbilitySystemComponent() const
{
	return Comp_AbilitySystem;
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
