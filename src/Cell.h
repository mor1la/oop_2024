#ifndef CELL_H
#define CELL_H


#include "modules.h"
#include "Ship.h"

enum class CellState {
    unknown,
    empty,
    ship
};

class Cell{
    private:
        Ship* ship;
        int shipIndex;
        int index;
        CellState state;
    public:
        Cell();

        void setShip(Ship* ship_);
 
        void setIndex(int indexSeg);
 
        void setState(CellState state);

        Ship* getShip();

        int getIndex();

        CellState getState();

        bool isAttackable();

        int getShipIndex();

        nlohmann::json toJson();

        void fromJson(nlohmann::json& j);
};


#endif