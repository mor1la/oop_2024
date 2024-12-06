#ifndef GAMESTATEENEMY_H
#define GAMESTATEENEMY_H

#include "GameField.h"
#include "ShipManager.h"
#include "modules.h"
#include "IGameState.h"

class GameStateEnemy : public IGameState  {
protected:
    GameField field;
    ShipManager shipManager;
public:
    // GameStateEnemy(int width = 10, int height = 10, std::vector<int> lengths = {4, 3, 3, 2, 2, 2, 1, 1, 1, 1});
    GameStateEnemy(int width = WIDTH, int height = HEIGHT, std::vector<int> lengths = std::vector<int>(LENGTHS));

    void reset() override; 

    ShipManager& getShipManager() override;
    
    GameField& getGameField() override;

    friend std::istream& operator>> (std::istream& is, GameStateEnemy& state);

    friend std::ostream& operator<< (std::ostream& os, GameStateEnemy& state);

    void save(std::string name) override;

    void load(std::string name) override;

    nlohmann::json toJson();

    void fromJson(nlohmann::json& j);
};



#endif