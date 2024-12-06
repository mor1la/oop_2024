#ifndef COORDHOLDER_H
#define COORDHOLDER_H

#include "modules.h"
#include "IInfoHolder.h"
#include "CoordReader.h"

class CoordHolder : public IInfoHolder {
private:
    std::pair<int, int> coords;
    CoordReader reader;
public:
    void need() override;
    
    std::pair<int, int> getCoords();

};

#endif