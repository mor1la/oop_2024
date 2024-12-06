#ifndef DOUBLEDAMAGECREATOR_H
#define DOUBLEDAMAGECREATOR_H


#include "modules.h"
#include "ICreator.h"
#include "DoubleDamageAbility.h"



class DoubleDamageCreator : public ICreator {
public:
    IAbility* createAbility() override;
    nlohmann::json toJson() override;
};

#endif