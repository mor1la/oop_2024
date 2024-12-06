#include "DoubleDamageCreator.h"

IAbility* DoubleDamageCreator::createAbility() {
    DoubleDamageAbility* ability = new DoubleDamageAbility();
    return ability;
}

nlohmann::json DoubleDamageCreator::toJson () {
    return nlohmann::json{
        {"ability", "double damage"}
    };
}