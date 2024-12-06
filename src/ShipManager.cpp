#include "ShipManager.h"

ShipManager::ShipManager(std::vector<int> lengths) {
    for (int i = 0; i < lengths.size(); i++)
    {
        if (lengths[i] > 0 && lengths[i] < 5)
        {
            ships.emplace_back(lengths[i], true, i);
        }     
    }
}

int ShipManager::getAmount(){
    return ships.size();
}

std::vector<Ship>& ShipManager::getShips(){
    return ships;
}

bool ShipManager::areAllShipsDestroyed()
{
    for (int i = 0; i < getAmount(); i++){
        if (ships[i].getIsDesrtoyed() == false){
            return false;
        }
    }
    return true;
}

nlohmann::json ShipManager::toJson()
{
    nlohmann::json shipsArray = nlohmann::json::array();
    for (auto& ship : ships)
    {
        shipsArray.push_back(ship.toJson());
    }

    return nlohmann::json{
        {"ships", shipsArray}
    };
}

void ShipManager::fromJson(nlohmann::json &j)
{
    auto shipsArray = j["ships"];
    ships.clear();
    for (auto& ship : shipsArray)
    {
        Ship curr(1, true, -1);
        curr.fromJson(ship);
        ships.push_back(curr);
    }
}
