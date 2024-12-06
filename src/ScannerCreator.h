#ifndef SCANNERCREATOR_H
#define SCANNERCREATOR_H


#include "modules.h"
#include "ICreator.h"
#include "ScannerAbility.h"
#include "AbilityResponse.h"
#include "CoordHolder.h"

class ScannerCreator : public ICreator {
private:
    CoordHolder& coordHolder;
    GameField& field;
public:
    ScannerCreator(CoordHolder& coordHolder, GameField& field): coordHolder(coordHolder), field(field) {};
    IAbility* createAbility() override;
    nlohmann::json toJson() override;
};

#endif