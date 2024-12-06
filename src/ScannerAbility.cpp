#include "ScannerAbility.h"



void ScannerAbility::useAbility(AbilityResponse& abilityResponse){
    int newX = coords.first + 2;
    int newY = coords.second + 2;
    for (int x = coords.first; x < newX; x++){
        for (int y = coords.second; y < newY; y++){
            if (isCoordsCorrect(field.getHeight(), field.getWidth(), x, y)){
                if (field.getCell(x, y).getShip()){
                    abilityResponse.setScannerResult(true);
                    break;
                }
            }
        }
    }
    abilityResponse.setScannerResult(false);
    abilityResponse.setLastUsedAbility(AbilityResponse::Ability::Scanner);
}


//возвращает класс с информацией
    