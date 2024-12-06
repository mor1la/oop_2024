#include "AbilityResponse.h"




void AbilityResponse::setScannerResult(bool scannerResult){
    this->scannerResult = scannerResult;
}

void AbilityResponse::setIsDoubleDamageActivated(bool isDoubleDamageActivated){
    this->isDoubleDamageActivated = isDoubleDamageActivated;
}
    
bool AbilityResponse::getScannerResult(){
    return scannerResult;
}

bool AbilityResponse::getIsDoubleDamageActivated(){
    return isDoubleDamageActivated;
}
void AbilityResponse::setLastUsedAbility(Ability ability){
    this->lastUsedAbility = ability;
}

AbilityResponse::Ability AbilityResponse::getLastUsedAbility(){
    return lastUsedAbility;
}

void AbilityResponse::GetAbilityResult(){
    switch (lastUsedAbility)
    {
    case AbilityResponse::Ability::DoubleDamage:
        std::cout << "Double damage success"<< "\n";
        break;
    case AbilityResponse::Ability::Scanner:
        if(this->scannerResult == false){
            std::cout << "Scanner detect ship"<< "\n";
        }else{
            std::cout << "These area is clear"<< "\n";
        }
        break;
    case AbilityResponse::Ability::RandomFire:
            std::cout << "RandomFire success"<< "\n";
        break;
    default:
        break;
    }
}

nlohmann::json AbilityResponse::toJson()
{
    return nlohmann::json{
        {"scannerResult", scannerResult},
        {"isDoubleDamageActivated", isDoubleDamageActivated},
        {"lastUsedAbility", static_cast<int>(lastUsedAbility)}
    };
}

void AbilityResponse::fromJson(nlohmann::json &j)
{
    scannerResult = j["scannerResult"];
    isDoubleDamageActivated = j["isDoubleDamageActivated"];
    lastUsedAbility = static_cast<Ability>(j["lastUsedAbility"]);
}
