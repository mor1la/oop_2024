#ifndef ICREATOR_H
#define ICREATOR_H

#include "IAbility.h"


class ICreator {    
public:
    virtual IAbility* createAbility() = 0;
    virtual ~ICreator() {}

    virtual nlohmann::json toJson() = 0;
};

#endif