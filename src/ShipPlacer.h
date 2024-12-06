#ifndef SHIPPLACER_H
#define SHIPPLACER_H


#include "modules.h"
#include "ShipManager.h"
#include "CoordHolder.h"
#include "GameField.h"



class ShipPlacer {
public:
    static void placeShipsForPlayer(GameField &field, ShipManager &shipManager, CoordHolder &coordHolder);
    static void placeShipsForEnemy(GameField &field, ShipManager &shipManager);
};

#endif