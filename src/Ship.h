#ifndef SHIP_H
#define SHIP_H


#include "modules.h"


enum class SegmentState {
    full,      
    damaged,   
    destroyed   
};

class Ship{
    private:
        int length;
        bool horizontal;
        bool isDestroyed;
        int shipIndex;
        std::vector <SegmentState> segments;
        void checkIsDestroyed();
    public:
        Ship(int length, bool horizontal, int shipIndex);

        void setOrientation(bool orient);

        void hit(int index, int amount = 1);

        int getLength() const;

        bool isHorizontal() const;

        SegmentState getState(int index);
        
        bool getIsDesrtoyed();

        int getIndex();

        nlohmann::json toJson();

        void fromJson(nlohmann::json& j);
};

#endif