#ifndef SHIPMANAGER_H
#define SHIPMANAGER_H


#include "modules.h"
#include "Ship.h"

class ShipManager {
private:
    std::vector<Ship> ships;
public:
    // ShipManager(std::vector<int> lengths = {4, 3, 3, 2, 2, 2, 1, 1, 1, 1});
    ShipManager(std::vector<int> lengths = std::vector<int>(LENGTHS));

    int getAmount();

    std::vector<Ship>& getShips();

    bool areAllShipsDestroyed();

    nlohmann::json toJson();

    void fromJson(nlohmann::json& j);
};

#endif