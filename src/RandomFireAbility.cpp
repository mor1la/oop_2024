#include "RandomFireAbility.h"



void RandomFireAbility::useAbility(AbilityResponse& abilityResponse){
    int counter = 0;
    while (counter < 10000){
        auto& ships = shipManager.getShips();
        Ship& ship = ships[getRandomNum(0, shipManager.getAmount())];
        int randomIndex = getRandomNum(0, ship.getLength());
        if (ship.getState(randomIndex) != SegmentState::destroyed){
            ship.hit(randomIndex);
            break;
        }
        counter++;
    }
    abilityResponse.setLastUsedAbility(AbilityResponse::Ability::RandomFire);
}
