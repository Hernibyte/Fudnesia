// hzxynox

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "FunesiaAbilitySystemComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class FUDNESIA_API UFunesiaAbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()

public:
	UFunesiaAbilitySystemComponent();

	virtual void BeginPlay() override;

	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;
	
};
