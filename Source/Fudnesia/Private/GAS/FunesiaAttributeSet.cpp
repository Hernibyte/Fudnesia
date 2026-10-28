// hzxynox


#include "GAS/FunesiaAttributeSet.h"

#include "Net/UnrealNetwork.h"

UFunesiaAttributeSet::UFunesiaAttributeSet()
{
	InitStamina(100.f);
	InitMaxStamina(100.f);
}

void UFunesiaAttributeSet::GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	
	DOREPLIFETIME(UFunesiaAttributeSet, Stamina);
	DOREPLIFETIME(UFunesiaAttributeSet, MaxStamina);
}
