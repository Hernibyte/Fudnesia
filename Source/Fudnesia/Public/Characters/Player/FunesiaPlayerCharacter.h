// hzxynox

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "InputMappingContext.h"
#include "Fudnesia/Public/Characters/FunesiaBaseCharacter.h"
#include "FunesiaPlayerCharacter.generated.h"

class UFunesiaAttributeSet;
class UFunesiaAbilitySystemComponent;
class UCameraComponent;
class USpringArmComponent;
struct FInputActionValue;
class UInputAction;

UCLASS()
class FUDNESIA_API AFunesiaPlayerCharacter : public AFunesiaBaseCharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	AFunesiaPlayerCharacter();

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;
	
	virtual void PawnClientRestart() override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	
protected:
	UPROPERTY(EditDefaultsOnly, Category="Input")
	TObjectPtr<UInputAction> IA_Move;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Component")
	TObjectPtr<USpringArmComponent> Comp_SpringArm;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Component")
	TObjectPtr<UCameraComponent> Comp_Camera;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Component")
	TObjectPtr<UFunesiaAbilitySystemComponent> Comp_AbilitySystem;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Component")
	TObjectPtr<UFunesiaAttributeSet> Comp_AttributeSet;
	
	UPROPERTY(EditAnywhere, Category="Input")
	TSoftObjectPtr<UInputMappingContext> IMC_Default;
	UPROPERTY(EditAnywhere, Category="Input")
	int32 IMC_Default_Priority = 0;
	
private:
	void Input_Move(const FInputActionValue& InputValue);
	
};
