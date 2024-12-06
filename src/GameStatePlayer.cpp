#include "GameStatePlayer.h"


GameStatePlayer::GameStatePlayer(int width, int height, std::vector<int> lengths): 
    field(width, height), shipManager(lengths), coordHolder(CoordHolder()), abilityResponse(AbilityResponse()), abilityManager(field, coordHolder, shipManager), 
    round(1), numberOfWins(0), needNewField(true){};

void GameStatePlayer::reset(){
    field = GameField(field.getWidth(), field.getHeight()); 
    shipManager = ShipManager();
}

AbilityManager &GameStatePlayer::getAbilityManager(){
    return abilityManager;
}

CoordHolder &GameStatePlayer::getCoordHolder(){
    return coordHolder;
}

int GameStatePlayer::getNumberOfWins(){
    return numberOfWins;
}

void GameStatePlayer::save (std::string name) {
    std::ofstream file (name);

    if (file.is_open()) {
        file << *this;
        file.close();
    }
}


void GameStatePlayer::load (std::string name) {
    std::ifstream file (name);

    if (file.is_open()) {
        file >> *this;
        file.close();
    }
}

nlohmann::json GameStatePlayer::toJson()
{
    return nlohmann::json{
        {"PlayerField", field.toJson()},
        {"PlayerShipManager", shipManager.toJson()},
        {"abilityManager", abilityManager.toJson()},
        {"abilityResponse", abilityResponse.toJson()},
        {"numberOfWins", numberOfWins},
        {"round", round},
        {"needNewField", needNewField}
    };
}

void GameStatePlayer::fromJson(nlohmann::json &j)
{
    field.fromJson(j["PlayerField"]);
    shipManager.fromJson(j["PlayerShipManager"]);
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

    abilityManager = AbilityManager(field, coordHolder, shipManager);
    abilityManager.fromJson(j["abilityManager"]);
    
    abilityResponse.fromJson(j["abilityResponse"]);

    numberOfWins = j["numberOfWins"];
    round = j["round"];
    needNewField = j["needNewField"];
}

int GameStatePlayer::getRound(){
    return round;
}

ShipManager &GameStatePlayer::getShipManager(){
    return shipManager;
}

GameField &GameStatePlayer::getGameField(){
    return field;
}

void GameStatePlayer::setRound(){
    round++;
}

void GameStatePlayer::setNumberOfWins(){
    numberOfWins++;
}

AbilityResponse& GameStatePlayer::getAbilityResponse(){
    return abilityResponse;
}

void GameStatePlayer::setNeedNewField(bool needNewField_){
    needNewField = needNewField_;
}

bool GameStatePlayer::getNeedNewField(){
    return needNewField;
}

std::istream &operator>>(std::istream &is, GameStatePlayer &state)
{
    nlohmann::json j;
    is >> j;
    state.fromJson(j);
    return is;
}

std::ostream& operator<< (std::ostream& os, GameStatePlayer& state) {
    os << state.toJson().dump(4);
    return os;
}
