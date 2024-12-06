#include "modules.h"



bool isCoordsCorrect(int width, int height, int x, int y) { 
    if ((x < 0 || x >= width) || (y < 0 || y >= height)) { 
        std::cout << "Coordinates are out of bounds - x: " << x << ", y: " << y << '\n'; 
        return false; 
    } 
    return true;
}

int getRandomNum(int min, int max)
{
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distr(min, max - 1);
    return distr(gen);
}

void clearConsole() {
    std::cout << "\033[H\033[J";
}