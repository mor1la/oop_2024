#ifndef RANDOMFIREABILITY_H
#define RANDOMFIREABILITY_H

#include "IAbility.h"
#include "AbilityResponse.h"
#include "IInfoHolder.h"
#include "GameField.h"

class RandomFireAbility : public IAbility{
private:
    GameField& field;
    ShipManager& shipManager;
public:
    RandomFireAbility(GameField& field, ShipManager& shipManager): field(field), shipManager(shipManager) {};
    void useAbility(AbilityResponse& abilityResponse) override;
};

#endif