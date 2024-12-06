#ifndef SCANNERABILITY_H
#define SCANNERABILITY_H

#include "IAbility.h"
#include "AbilityResponse.h"
#include "IInfoHolder.h"
#include "GameField.h"

class ScannerAbility : public IAbility{
private:
    std::pair<int, int> coords;
    GameField& field;
public:
    ScannerAbility(std::pair<int, int> coords, GameField& field): coords(coords), field(field) {};
    void useAbility(AbilityResponse& abilityResponse) override;
};

#endif