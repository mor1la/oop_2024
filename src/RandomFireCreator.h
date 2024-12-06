#ifndef RANDOMFIRECREATOR_H
#define RANDOMFIRECREATOR_H

#include "modules.h"
#include "ICreator.h"
#include "RandomFireAbility.h"

class RandomFireCreator : public ICreator {
private:
    ShipManager& shipManager;
    GameField& field;
public:
    RandomFireCreator(GameField& field, ShipManager& shipManager): shipManager(shipManager), field(field) {};
    IAbility* createAbility() override;
    nlohmann::json toJson() override;
};

#endif