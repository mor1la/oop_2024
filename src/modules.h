#ifndef MODULES_H
#define MODULES_H

#define WIDTH 10
#define HEIGHT 10
#define LENGTHS {1}


#include <iostream>
#include <vector>
#include <stdexcept>
#include <unordered_map>
#include <utility>
#include <memory>
#include <queue>
#include <random>
#include <chrono>
#include <exception>
#include <fstream>
#include "json.hpp"


bool isCoordsCorrect(int height, int width, int x, int y);

int getRandomNum(int min, int max);

void clearConsole();

#endif  