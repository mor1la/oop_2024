#include "RandomFireCreator.h"



IAbility* RandomFireCreator::createAbility() {
    RandomFireAbility* ability = new RandomFireAbility(field, shipManager);
    return ability;
}

nlohmann::json RandomFireCreator::toJson () {
    return nlohmann::json{
        {"ability", "random fire"}
    };
}