#include "Ship.h"

Ship::Ship(int length, bool horizontal, int shipIndex){
    this->length = length;
    this->horizontal = horizontal;
    this->segments = std::vector<SegmentState>(length, SegmentState::full);
    this->isDestroyed = false;
    this->shipIndex = shipIndex;
}
void Ship::setOrientation(bool orient){
    this->horizontal = orient;
}

void Ship::hit(int index, int amount){
    if (index < 0 || index > length - 1){
        std::cout << "Ошибка в функции hit: неверный индекс";
        return;
    }

    for (int i = 0; i < amount; i++){
        if (segments[index] == SegmentState::full){
            segments[index] = SegmentState::damaged;
        }else if (segments[index] == SegmentState::damaged){
            segments[index] = SegmentState::destroyed;
        }
    }
    checkIsDestroyed();
}

int Ship::getLength() const {
    return length;
}

bool Ship::isHorizontal() const {
    return horizontal;
}

SegmentState Ship::getState(int index) {
    return segments[index];
}

void Ship::checkIsDestroyed(){
    for (int i = 0; i < length; i++){
        if (segments[i] != SegmentState::destroyed){
            this->isDestroyed = false;
            return;
        }
    }
    this->isDestroyed = true;
}

bool Ship::getIsDesrtoyed(){
    
    return isDestroyed;
}

int Ship::getIndex()
{
    return shipIndex;
}

nlohmann::json Ship::toJson()
{
    nlohmann::json segmentsArray = nlohmann::json::array();
    for (auto& seg : segments)
    {
        segmentsArray.push_back(static_cast<int>(seg));
    }

    return nlohmann::json{
        {"length", length},
        {"horizontal", horizontal},
        {"isDestroyed", isDestroyed},
        {"shipIndex", shipIndex},
        {"segmentsArray", segmentsArray},
    };
}

void Ship::fromJson(nlohmann::json &j)
{
    length = j["length"];
    horizontal = j["horizontal"];
    isDestroyed = j["isDestroyed"];
    shipIndex = j["shipIndex"];

    segments.clear();
    auto segmentsArray = j["segmentsArray"];
    for (auto& seg : segmentsArray)
    {
        segments.push_back(static_cast<SegmentState>(seg));
    }
}
