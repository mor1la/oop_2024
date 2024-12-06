#ifndef EXEPTION_H
#define EXEPTION_H

#include "modules.h"



class AttackOutOfBoundsException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Error: Attack coordinates are out of bounds.";
    }
};

class NoAbilitiesException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Error: No abilities available to use.";
    }
};

class InvalidPlacementException : public std::exception {
    const char* what() const noexcept override {
        return "Error: Invalid placement of ship: overlapping or adjacent to another ship.";
    }
};

#endif