#include "AbilityManager.h"

AbilityManager::AbilityManager(GameField& field, CoordHolder& coordHolder, ShipManager& shipManager)
: field(field), coordHolder(coordHolder), shipManager(shipManager) {
    std::vector<ICreator*> array = {};
    array.push_back(new DoubleDamageCreator());
    array.push_back(new ScannerCreator(coordHolder, field));
    array.push_back(new RandomFireCreator(field, shipManager));

    while (!array.empty()){
        int rand = getRandomNum(0, array.size());
        abilitiesCreatorsQueue.push(array[rand]);
        array.erase(array.begin() + rand);
    }
}

void AbilityManager::activateAbility(AbilityResponse& response){
    if (abilitiesCreatorsQueue.empty()){
        throw NoAbilitiesException();
    }
    ICreator* abilityCreator = abilitiesCreatorsQueue.front();
    abilitiesCreatorsQueue.pop();

    IAbility* ability = abilityCreator->createAbility();
    delete abilityCreator;
    ability->useAbility(response);
    delete ability;
}

AbilityManager &AbilityManager::operator=(const AbilityManager &other)
{

    if (this != &other)
    {

    }

    return *this;
}

void AbilityManager::addRandomAbility(){
    std::vector <ICreator*> array = {};
    array.push_back(new DoubleDamageCreator());
    array.push_back(new ScannerCreator(coordHolder, field));
    array.push_back(new RandomFireCreator(field, shipManager));
    int rand = getRandomNum(0, array.size());
    abilitiesCreatorsQueue.push(array[rand]);
}

nlohmann::json AbilityManager::toJson ()
{
    nlohmann::json abilities = nlohmann::json::array();
    std::queue<ICreator*> copyQueue = abilitiesCreatorsQueue;

    while (!copyQueue.empty()) {
        abilities.push_back(copyQueue.front()->toJson());
        copyQueue.pop();
    }

    return nlohmann::json{
        {"abilities", abilities}
    };
}


void AbilityManager::fromJson (nlohmann::json& j) {
    auto abilities = j["abilities"];
    while (!abilitiesCreatorsQueue.empty())
    {
        abilitiesCreatorsQueue.pop();
    }
    for (auto& item : abilities) {
        std::string ability = item["ability"].get<std::string>(); 
        if (ability == "random fire") {
            abilitiesCreatorsQueue.push(new RandomFireCreator(field, shipManager));
        } else if (ability == "double damage") {
            abilitiesCreatorsQueue.push(new DoubleDamageCreator());
        } else if (ability == "scanner") {
            abilitiesCreatorsQueue.push(new ScannerCreator(coordHolder, field));
        }
    }
}