#include "Cell.h"



Cell::Cell(){
    this->ship = nullptr;
    this->index = -1;
    this->state = CellState::unknown;
    this->shipIndex = -1;
}

void Cell::setShip(Ship* ship_) { 
    this->ship = ship_;
    this->shipIndex = ship_ ? ship_->getIndex() : -1;
} 

void Cell::setIndex(int indexSeg) { 
    this->index = indexSeg; 
} 

void Cell::setState(CellState state) { 
    this->state = state; 
} 

Ship* Cell::getShip(){
    return ship;
}

int Cell::getIndex(){
    return index;
}

CellState Cell::getState(){
    return state;
}

bool Cell::isAttackable()
{
   if (state == CellState::empty || (state == CellState::ship && ship->getState(index) == SegmentState::destroyed)){
        return false;
   }
   return true;
}

int Cell::getShipIndex()
{
    return shipIndex;
}

nlohmann::json Cell::toJson()
{
    return nlohmann::json{
        {"index", index},
        {"state", static_cast<int>(state)},
        {"shipIndex", ship ? shipIndex : -1}
    };
}

void Cell::fromJson(nlohmann::json &j)
{
    index = j["index"];
    state = static_cast<CellState>(j["state"]);
    shipIndex = j["shipIndex"];
}
