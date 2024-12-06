#include "ShipPlacer.h"



void ShipPlacer::placeShipsForPlayer(GameField &field, ShipManager &shipManager, CoordHolder &coordHolder) {
    for (auto &ship : shipManager.getShips()) {
        bool placed = false;

        while (!placed) {
            std::cout << "x y and orientation (1 horizontal, 0 vertical) for a ship of length " << ship.getLength() << ": ";
            int x, y, orientation;
            std::cin >> x >> y >> orientation;
            bool isHorizontal = (orientation == 1);
            ship.setOrientation(isHorizontal);
            if (field.canPlaceShip(ship, x, y)) {
                field.placeShip(ship, isHorizontal, x, y);
                std::cout << "Ship placed successfully!\n";
                placed = true;
            } else {
                std::cout << "Invalid placement. Try again.\n";
            }
        }
    }

    std::cout << "All player ships have been placed.\n";
}


void ShipPlacer::placeShipsForEnemy(GameField &field, ShipManager &shipManager) {
    for (auto &ship : shipManager.getShips()) {
        bool placed = false;

        while (!placed) {
            std::pair<int, int> coords = std::make_pair(getRandomNum(0, field.getWidth()), getRandomNum(0, field.getHeight()));
            bool isHorizontal = getRandomNum(0, 2); 
            ship.setOrientation(isHorizontal);
            if (field.canPlaceShip(ship, coords.first, coords.second)) {
                field.placeShip(ship, isHorizontal, coords.first, coords.second);
                placed = true;
            }
        }
    }

    std::cout << "All enemy ships have been placed.\n";
}