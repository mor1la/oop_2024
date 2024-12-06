#include "GameStateEnemy.h"


GameStateEnemy::GameStateEnemy(int width, int height, std::vector<int> lengths):field(width, height), shipManager(lengths){};

void GameStateEnemy::reset(){
    field = GameField(field.getWidth(), field.getHeight()); 
    shipManager = ShipManager();
}

GameField &GameStateEnemy::getGameField(){
    return field;
}

void GameStateEnemy::save(std::string name)
{
    std::ofstream file (name);

    if (file.is_open()) {
        file << *this;
        file.close();
    }
}

void GameStateEnemy::load(std::string name)
{
    std::ifstream file (name);

    if (file.is_open()) {
        file >> *this;
        file.close();
    }
}

nlohmann::json GameStateEnemy::toJson()
{
    return nlohmann::json{
        {"enemyField", field.toJson()},
        {"enemyShipManager", shipManager.toJson()}
    };
}

void GameStateEnemy::fromJson(nlohmann::json &j)
{
    field.fromJson(j["enemyField"]);
    shipManager.fromJson(j["enemyShipManager"]);
    for (int y = 0; y < field.getHeight(); y++)
    {
        for (int x = 0; x < field.getWidth(); x++)
        {
            if (field.getCell(x, y).getIndex() != -1)
            {
                std::vector<Ship>& ships = shipManager.getShips();
                for (Ship& ship : ships)
                {
                    if (ship.getIndex() == field.getCell(x, y).getShipIndex())
                    {
                        field.getCell(x, y).setShip(&ship);
                    }
                }
            }
            else
            {
                field.getCell(x, y).setShip(nullptr);
            }
        }
    }
}

ShipManager &GameStateEnemy::getShipManager(){
    return shipManager;
}


std::istream &operator>>(std::istream &is, GameStateEnemy &state)
{
    nlohmann::json j;
    is >> j;
    state.fromJson(j);
    return is;
}

std::ostream& operator<< (std::ostream& os, GameStateEnemy& state) {
    os << state.toJson().dump(4);
    return os;
}