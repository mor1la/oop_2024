#ifndef GAMESTATEPLAYER_H
#define GAMESTATEPLAYER_H

#include "GameField.h"
#include "AbilityManager.h"
#include "ShipManager.h"
#include "IGameState.h"
#include "modules.h"


class GameStatePlayer : public IGameState {
private:
    GameField field;
    ShipManager shipManager;
    AbilityManager abilityManager;
    AbilityResponse abilityResponse;
    CoordHolder coordHolder;
    int numberOfWins;
    int round;
    bool needNewField;
public:
    // GameStatePlayer(int width = 10, int height = 10, std::vector<int> lengths = {4, 3, 3, 2, 2, 2, 1, 1, 1, 1});
    GameStatePlayer(int width = WIDTH, int height = HEIGHT, std::vector<int> lengths = std::vector<int>(LENGTHS));

    void reset() override;

    AbilityManager &getAbilityManager();

    CoordHolder& getCoordHolder();

    int getWins();

    int getRound();

    ShipManager& getShipManager() override;

    GameField& getGameField() override;

    void setRound();

    void setNumberOfWins();

    AbilityResponse &getAbilityResponse();

    void setNeedNewField(bool needNewField_);

    bool getNeedNewField();

    int getNumberOfWins();

    friend std::istream& operator>> (std::istream& is, GameStatePlayer& state);

    friend std::ostream& operator<< (std::ostream& os, GameStatePlayer& state);

    void save(std::string name) override;

    void load(std::string name) override;

    nlohmann::json toJson();

    void fromJson(nlohmann::json& j);
};

#endif