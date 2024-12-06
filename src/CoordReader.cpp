#include "CoordReader.h"

std::pair<int, int> CoordReader::readCoordinates() {
    int x, y;
    std::cout << "Coordinates:";
    std::cin >> x >> y; 
    return std::make_pair(x, y); 
}
