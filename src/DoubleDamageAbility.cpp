#include "DoubleDamageAbility.h"



void DoubleDamageAbility::useAbility(AbilityResponse& abilityResponse){
    abilityResponse.setIsDoubleDamageActivated(true);
    abilityResponse.setLastUsedAbility(AbilityResponse::Ability::DoubleDamage);
}
