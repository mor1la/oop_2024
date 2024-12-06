#ifndef GAMEFIELD_H
#define GAMEFIELD_H


#include "modules.h"
#include "ShipManager.h"
#include "Cell.h"
#include "Exeption.h"

class GameField{
private:
    int height;
    int width;
    std::vector<std::vector<Cell>> field;
        
public:
    GameField(int height = 10, int width = 10);

    bool checkCoordinateForAttack(int x, int y);

    bool canPlaceShip(Ship ship, int x, int y);

    int getHeight();

    int getWidth();

    Cell& getCell(int x, int y);

    void placeShip(Ship& ship, bool isHorizontal, int x, int y);

    bool attack(int x, int y, int amount);

    void randomAttack();
    void drawField(bool isMine);

    nlohmann::json toJson();

    void fromJson(nlohmann::json& j);
};

#endif