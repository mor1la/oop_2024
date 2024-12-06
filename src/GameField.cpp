#include "GameField.h"



bool GameField::checkCoordinateForAttack(int x, int y){
    if (isCoordsCorrect(height, width, x, y)){
        if (field[y][x].getShip()->getState(field[y][x].getIndex()) == SegmentState::full){
            return true;
        }
    }
    return false;
}

bool GameField::canPlaceShip(Ship ship, int x, int y) {
    if (!isCoordsCorrect(height, width, x, y)) 
        return false; 

    int length = ship.getLength(); 
    bool isHorizontal = ship.isHorizontal(); 

    if ((isHorizontal && x + length > width) || (!isHorizontal && y + length > height)) 
        return false; 

    for (int i = -1; i <= length; ++i) { 
        for (int j = -1; j <= 1; ++j) { 
            int checkX = isHorizontal ? x + i : x + j; 
            int checkY = isHorizontal ? y + j : y + i; 

            if (checkX < 0 || checkX >= width || checkY < 0 || checkY >= height) 
                continue; 

            if (field[checkY][checkX].getIndex() != -1) 
                return false; 
        } 
    } 

    return true; 
}


GameField::GameField(int height, int width){
    this->height = height;
    this->width = width;
    this->field = std::vector<std::vector<Cell>>(height, std::vector<Cell>(width)); 
}

int GameField::getHeight(){
    return this->height;
}

int GameField::getWidth(){
    return this->width;
}

Cell& GameField::getCell(int x, int y){

    return field[y][x];
}

void GameField::placeShip(Ship& ship, bool isHorizontal, int x, int y){
    ship.setOrientation(isHorizontal);
    if (!canPlaceShip(ship, x, y)){ 
        return; 
    } 
    if (isHorizontal){
        for (int i = 0; i < ship.getLength(); i++){
            field[y][x + i].setShip(&ship);
            field[y][x + i].setIndex(i);
            field[y][x + i].setState(CellState::ship);
        }
    }else{
        for (int i = 0; i < ship.getLength(); i++){
            field[y + i][x].setShip(&ship);
            field[y + i][x].setIndex(i);
            field[y + i][x].setState(CellState::ship);
        }               
    }
}

bool GameField::attack(int x, int y, int amount){
    if (!isCoordsCorrect(width, height, x, y)){
        throw AttackOutOfBoundsException();
    }

    if (field[y][x].isAttackable()){
        if (field[y][x].getShip()){
            field[y][x].getShip()->hit(field[y][x].getIndex(), amount);
        }else{
            field[y][x].setState(CellState::empty);
        }
        return true;
    }
    return false;
}

void GameField::randomAttack(){
    int counter = 0;
    while(counter < 10000){
        int x = getRandomNum(0, width);
        int y = getRandomNum(0, height);
        if (field[y][x].isAttackable()){
            attack(x, y, 1);
            break;
        }
        counter++;
    }
}


void GameField::drawField(bool isMine) {
    char rowLabels[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    std::cout << "  "; 
    for (int i = 0; i < width; ++i) {
        std::cout << i << " "; 
    }
    std::cout << '\n';
    for (int y = 0; y < height; y++){
        std::cout << rowLabels[y] << " ";  
        for (int x = 0; x < width; x++) {
            Ship* ship = field[y][x].getShip();

            if (ship != nullptr){
                if (ship->getState(field[y][x].getIndex()) == SegmentState::full){
                    if (isMine)
                        std::cout << "# ";
                    else
                        std::cout << "~ ";
                }else if (ship->getState(field[y][x].getIndex()) == SegmentState::damaged){
                    std::cout << "+ ";
                }else if (ship->getState(field[y][x].getIndex()) == SegmentState::destroyed) {
                    std::cout << "X ";
                }
            }else if (field[y][x].getState() == CellState::empty){
                std:: cout << "0 ";
            }else {
                std:: cout << "~ ";
            }
        }
        std::cout << "\n";
    }
}

nlohmann::json GameField::toJson()
{
    nlohmann::json jField = nlohmann::json::array();
    for (int y = 0; y < height; y++)
    {
        nlohmann::json jRow = nlohmann::json::array();
        for (int x = 0; x < width; x++)
        {
            jRow.push_back(field[y][x].toJson());
        }
        jField.push_back(jRow);
    }

    return nlohmann::json{
        {"width", width},
        {"height", height},
        {"field", jField}
    };
}

void GameField::fromJson(nlohmann::json &j)
{
    width = j["width"];
    height = j["height"];
    auto jField = j["field"];
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            field[y][x].fromJson(jField[y][x]);
        }
    }
}
