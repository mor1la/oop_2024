#include "ScannerCreator.h"



IAbility* ScannerCreator::createAbility() {
    coordHolder.need();
    std::pair<int, int> coords= coordHolder.getCoords();
    ScannerAbility* ability = new ScannerAbility(coords, field);
    return ability;
}

nlohmann::json ScannerCreator::toJson () {
    return nlohmann::json{
        {"ability", "scanner"}
    };
}