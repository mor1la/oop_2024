
#ifndef IABILITY_H
#define IABILITY_H


#include "modules.h"
#include "AbilityResponse.h"


class IAbility {
public:
    virtual void useAbility(AbilityResponse& abilityResponse) = 0;
    virtual ~IAbility() {}
};


#endif