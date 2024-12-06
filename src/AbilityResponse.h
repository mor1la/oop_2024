#ifndef ABILITYRESPONSE_H
#define ABILITYRESPONSE_H


#include "modules.h"


class AbilityResponse {
public:
    enum class Ability{
        DoubleDamage,
        Scanner,
        RandomFire
    };

private:
    bool scannerResult;
    bool isDoubleDamageActivated;
    Ability lastUsedAbility;
public:

    void setScannerResult(bool scannerResult);

    void setIsDoubleDamageActivated(bool isDoubleDamageActivated);
    
    bool getScannerResult();

    bool getIsDoubleDamageActivated();

    void setLastUsedAbility(Ability ability);
    
    Ability getLastUsedAbility();

    void GetAbilityResult();

    nlohmann::json toJson();

    void fromJson(nlohmann::json& j);
};

#endif