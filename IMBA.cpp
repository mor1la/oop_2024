#include <iostream>
#include <vector>
#include <stdexcept>
#include <unordered_map>
#include <utility>

enum class SegmentState {
    WHOLE,      
    DAMAGED,   
    DESTROYED   
};

struct Coords {
   int x;
   int y;
   Coords (int x, int y){
        this->x = x;
        this->y = y;
    }

    bool operator==(const Coords& other) const {
        return this->x == other.x && this->y == other.y;
    }

    bool operator!=(const Coords& other) const {
        return !(*this == other);
    }
};

enum class CellState {
    UNKNOWN,    // Неизвестно (изначально)
    EMPTY,      
    SHIP,
    HIT,   
    DESTROYED  
};

class Ship {
    private:
        int length;
        bool horizontal;
        std::vector <SegmentState> segments;
    public:
        Ship(int length, bool horizontal){
            this->length = length;
            this->horizontal = horizontal;
            this->segments = std::vector<SegmentState>(length, SegmentState::WHOLE);
        }

        void setOrientation(bool orient){
            this->horizontal = orient;
        }

        void hit(int index){
            if (index < 0 || index > length - 1)
                return;
            if (segments[index] == SegmentState::WHOLE){
                segments[index] = SegmentState::DAMAGED;
                return;
            }else if (segments[index] == SegmentState::DAMAGED){
                segments[index] = SegmentState::DESTROYED;
                return;
            }
        }

        int getLength() const {
            return length;
        }

        bool isHorizontal() const {
            return horizontal;
        }

        SegmentState getState(int index) {
            if (index < 0 || index > length - 1)
                return SegmentState::WHOLE;  //должен быть throw
            return segments[index];
        }
};

class ShipManager {
    private:
        std::vector<Ship> ships;
    public:
        ShipManager(std::vector<int> sizes) {
            for(int size: sizes){
                if (size > 0 && size < 5)
                    ships.emplace_back(size, true);
            }
        }

        Ship& getShip(int index) {
            return ships[index];
        }

        std::vector<Ship>& getShips(){
            return ships;
        }
};

class GameField {
    private:
        int height;
        int width;
        std::vector<std::vector<CellState>> field;
        std::vector<std::vector<CellState>> enemyField;
        std::vector<std::pair<Coords, Ship*>> shipByCoord;
        
        bool canPlaceShip(Ship ship, int x, int y){
            int length = ship.getLength();
            if (x > width || y  > height)
                return false;
   
            if (ship.isHorizontal()) {
                for (int i = 0; i < length; i++){
                    if (x + i >= width)
                        return false;
                }
                // Левая и правая границы
                if ((x > 0 && field[y][x - 1] == CellState::SHIP) ||
                    (x + length < width && field[y][x + length] == CellState::SHIP)) {
                    return false;
                }

                // Верхние углы
                if ((y > 0 && x > 0 && field[y - 1][x - 1] == CellState::SHIP) ||
                    (y > 0 && x + length < width && field[y - 1][x + length] == CellState::SHIP)) {
                    return false;
                }

                // Нижние углы
                if ((y + 1 < height && x > 0 && field[y + 1][x - 1] == CellState::SHIP) ||
                    (y + 1 < height && x + length < width && field[y + 1][x + length] == CellState::SHIP)) {
                    return false;
                }

                // Проверка по бокам для каждой части корабля
                for (int k = 0; k < length; k++) {
                    if ((y > 0 && field[y - 1][x + k] == CellState::SHIP) ||
                        (y + 1 < height && field[y + 1][x + k] == CellState::SHIP) ||
                        field[y][x + k] == CellState::SHIP) {
                        return false;
                    }
                }
            } else {
                for (int i = 0; i < length; i++){
                    if (y + i >= height)
                        return false;
                }

                // Верхняя и нижняя границы
                if ((y > 0 && field[y - 1][x] == CellState::SHIP) ||
                    (y + length < height && field[y + length][x] == CellState::SHIP)) {
                    return false;
                }

                // Верхние углы
                if ((y > 0 && x > 0 && field[y - 1][x - 1] == CellState::SHIP) ||
                    (y > 0 && x + 1 < width && field[y - 1][x + 1] == CellState::SHIP)) {
                    return false;
                }

                // Нижние углы
                if ((y + length < height && x > 0 && field[y + length][x - 1] == CellState::SHIP) ||
                    (y + length < height && x + 1 < width && field[y + length][x + 1] == CellState::SHIP)) {
                    return false;
                }

                // Проверка по бокам для каждой части корабля
                for (int k = 0; k < length; k++) {
                    if ((x > 0 && field[y + k][x - 1] == CellState::SHIP) ||
                        (x + 1 < width && field[y + k][x + 1] == CellState::SHIP) ||
                        field[y + k][x] == CellState::SHIP) {
                        return false;
                    }
                }
            }
            return true;    
        }

        bool checkState(int x, int y, CellState state){
            return field[y][x] == state;
        }

    public:
        GameField(int h, int w) {
            if (w < 0 || h < 0){
                return;
            }
            this->height = h;
            this->width = w;
            this->field = std::vector<std::vector<CellState>>(h, std::vector<CellState>(w, CellState::EMPTY));  
            this->enemyField = std::vector<std::vector<CellState>>(h, std::vector<CellState>(w, CellState::UNKNOWN));  
            this->shipByCoord = {};
        }

        void placeShip(Ship& ship, bool isHorizontal, int x, int y) {
            ship.setOrientation(isHorizontal);
            if (!canPlaceShip(ship, x, y))
                return;

            if (isHorizontal){
                for (int i = 0; i < ship.getLength(); i++){
                    field[y][x + i] = CellState::SHIP;
                }
            } else {
                for (int i = 0; i < ship.getLength(); i++){
                    field[y + i][x] = CellState::SHIP;
                }
            }
            shipByCoord.push_back({{x, y}, &ship});
        }

        void attack(int x, int y){
            int index = 0;
            if (checkState(x, y, CellState::SHIP) || checkState(x, y, CellState::HIT)){
                if (checkState(x, y, CellState::SHIP)){
                    field[y][x] = CellState::HIT;
                }else {
                    field[y][x] = CellState::DESTROYED;
                }
                while (x > 0 && (checkState(x - 1, y, CellState::SHIP) || checkState(x - 1, y, CellState::HIT) || checkState(x - 1, y, CellState::DESTROYED))){//добавить проверку на хит
                    index++;
                    x--;
                }
                while (y > 0 && (checkState(x, y - 1, CellState::SHIP) || checkState(x, y - 1, CellState::HIT) || checkState(x, y - 1, CellState::DESTROYED))){
                    index++;
                    y--;
                }
            }
            for (auto& p: shipByCoord){
                if (p.first ==  Coords(x, y)){
                    p.second->hit(index);
                    break;
                }
            }
        }

        void DrawField() {
            char rowLabels[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O','P', 'R', 'S', 'T'};
            std::cout << "  ";  // Пробел для выравнивания с буквами строк
            for (int i = 0; i < width; ++i) {
                std::cout << i << " "; 
            }
            std::cout << '\n';

            for (int y = 0; y < height; ++y) {
                std::cout << rowLabels[y] << " ";  
                for (int x = 0; x < width; ++x) {
                    switch (field[y][x]) {  
                        case CellState::EMPTY:
                            std::cout << "~ ";  // Пустое поле (вода)
                            break;
                        case CellState::SHIP:
                            std::cout << "# ";  // Корабль
                            break;
                        case CellState::HIT:
                            std::cout << "+ ";  // Попадание
                            break;
                        case CellState::DESTROYED:
                            std::cout << "X ";  // Попадание
                            break;
                        case CellState::UNKNOWN:
                            std::cout << "O ";  // Промах
                            break;
                    }
                }
                std::cout << '\n';  
            }
        }

};
//копирование и перемещения
int main(){
    GameField play (10, 10);
    std::vector<int> sizes = {4, 3, 3, 2, 1};
    std::vector<std::pair<int, int>> meow = {{1, 2}, {1, 4}, {3, 4}, {8, 4}, {8, 1}};
    std::vector<bool> woof = {true, false, false, false, false};
    ShipManager manager(sizes);
    int index = 0;
    for (auto& ship: manager.getShips()){
        play.placeShip(ship, woof[index], meow[index].first, meow[index].second);
        index++;
    }
    play.DrawField();
    play.attack(1, 2);
    play.DrawField();
    play.attack(1, 2);
    play.attack(3, 2);
    play.DrawField();
}
//потестить вайлы выводить из шеп менеджера все состояния корабля
//перемещние копирование
//сделать проверки
//изменить на чекер
// в методе атак координаты нужны положительные
//выставление кораблей корректность границ
//вражеское поле
