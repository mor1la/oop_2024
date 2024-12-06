#ifndef DOUBLEDAMAGEABILITY_H
#define DOUBLEDAMAGEABILITY_H
#include "IAbility.h"
#include "AbilityResponse.h"
#include "IInfoHolder.h"


class DoubleDamageAbility : public IAbility{
public:
    void useAbility(AbilityResponse& abilityResponse) override;
};

#endif