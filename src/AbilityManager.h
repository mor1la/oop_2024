#ifndef ABILITYMANAGER_H
#define ABILITYMANAGER_H


#include "modules.h"
#include "DoubleDamageCreator.h"
#include "ScannerCreator.h"
#include "RandomFireCreator.h"
#include  "IInfoHolder.h"
#include "ShipManager.h"
#include "GameField.h"
#include "CoordHolder.h"

class AbilityManager {
private:
    GameField& field;
    CoordHolder& coordHolder;
    ShipManager& shipManager;
    std::queue<ICreator*> abilitiesCreatorsQueue;
public:
    AbilityManager(GameField& field, CoordHolder& coordHolder, ShipManager& shipManager);

    void addRandomAbility();

    void activateAbility(AbilityResponse& response);
    
    AbilityManager& operator=(const AbilityManager& other);

    nlohmann::json toJson();

    void fromJson(nlohmann::json& j);
};

#endif