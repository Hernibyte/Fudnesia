// hzxynox

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "FunesiaBaseCharacter.generated.h"

UCLASS()
class FUDNESIA_API AFunesiaBaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AFunesiaBaseCharacter();

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
};
