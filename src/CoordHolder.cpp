#include "CoordHolder.h"





void CoordHolder::need(){
    coords = reader.readCoordinates();  
}

std::pair<int, int> CoordHolder::getCoords(){
    return coords;
}

