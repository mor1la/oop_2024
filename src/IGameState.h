#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "GameField.h"
#include "ShipManager.h"
#include "modules.h"

class IGameState {
public:

    virtual void reset() = 0; 

    virtual ShipManager& getShipManager() = 0;
    
    virtual GameField& getGameField() = 0;

    virtual void save (std::string name) = 0;

    virtual void load (std::string name) = 0;
};



#endif