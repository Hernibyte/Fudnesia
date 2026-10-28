// hzxynox

#pragma once

#include "CoreMinimal.h"
#include "Fudnesia/Public/Characters/FunesiaBaseCharacter.h"
#include "FunesiaPlayerCharacter.generated.h"

class UCameraComponent;
class USpringArmComponent;
struct FInputActionValue;
class UInputAction;

UCLASS()
class FUDNESIA_API AFunesiaPlayerCharacter : public AFunesiaBaseCharacter
{
	GENERATED_BODY()

public:
	AFunesiaPlayerCharacter();

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
protected:
	UPROPERTY(EditDefaultsOnly, Category="Input")
	TObjectPtr<UInputAction> IA_Move;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Component")
	TObjectPtr<USpringArmComponent> Comp_SpringArm;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Component")
	TObjectPtr<UCameraComponent> Comp_Camera;
	
private:
	void Input_Move(const FInputActionValue& InputValue);
	
};
