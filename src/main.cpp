#include "AbilityManager.h"
#include "GameField.h"
#include "IInfoHolder.h"
#include "AbilityResponse.h"
#include "GameManager.h"
#include "TempInput.h"
// int main(){
//     // GameField play1 (10, 10, true);
//     // GameField play2 (10, 10, false);   
//     // std::vector<int> sizes = {4, 3, 3, 2, 1};
//     // std::vector<std::pair<int, int>> meow = {{1, 2}, {1, 5}, {3, 4}, {8, 4}, {9, 9}};
//     // std::vector<bool> woof = {true, false, false, false, false};  
//     // ShipManager manager1(sizes);
//     // ShipManager manager2(sizes);
//     // // play1.drawField();
//     // // play2.drawField();
//     // int index = 0;
//     // for (auto& ship: manager1.getShips()){
//     //     play1.placeShip(ship, woof[index], meow[index].first, meow[index].second);
//     //     index++;
//     // }
//     // index = 0;
//     // for (auto& ship: manager2.getShips()){
//     //     play2.placeShip(ship, woof[index], meow[index].first, meow[index].second);
//     //     index++;
//     // }
//     // play1.drawField();
//     // play1.attack(3, 2);
//     // play1.attack(3, 2);
//     // play1.attack(3, 3);


//     // GameField play1 (10, 10, true);
//     // std::vector<int> sizes = {4};
//     // std::vector<std::pair<int, int>> coord = {{1, 2}};
//     // std::vector<bool> horiz = {true};  
//     // ShipManager manager1(sizes);
//     // AbilityManager abilitymanager1;
//     // Controller controller1(play1, manager1, abilitymanager1);
//     // play1.placeShip(manager1.getShips()[0], horiz[0], coord[0].first, coord[0].second);
//     // controller1.setXY(2, 2); // Устанавливаем координаты для атаки
//     // DoubleDamageAbility doubleDamage;
//     // doubleDamage.apply(controller1); // Применяем способность двойного урона
//     // play1.drawField();
//     // if (play1.getCell(2, 2).getShip()->getState(1) == SegmentState::destroyed){
//     //     std::cout << "OK\n";
//     // }
//     // for (int i = 0; i < manager1.getShips()[0].getLength(); i++){
//     //     if (manager1.getShips()[0].getState(i) == SegmentState::damaged){
//     //         std::cout << "OK" << '\n';
//     //     }
//     // }

//     // GameField play1 (10, 10, true);
//     // GameField play2 (10, 10, false);   
//     // std::vector<int> sizes = {4, 3, 3, 2, 1};
//     // std::vector<std::pair<int, int>> meow = {{1, 2}, {1, 5}, {3, 4}, {8, 4}, {9, 9}};
//     // std::vector<bool> woof = {true, false, false, false, false};  
//     // ShipManager manager1(sizes);
//     // ShipManager manager2(sizes);
//     // // play1.drawField();
//     // // play2.drawField();
//     // int index = 0;
//     // for (auto& ship: manager1.getShips()){
//     //     play1.placeShip(ship, woof[index], meow[index].first, meow[index].second);
//     //     index++;
//     // }
//     // index = 0;
//     // for (auto& ship: manager2.getShips()){
//     //     play2.placeShip(ship, woof[index], meow[index].first, meow[index].second);
//     //     index++;
//     // }
//     // play1.drawField();
//     // play2.drawField();
//     CoordHolder holder;
//     AbilityResponse response;
//     // AbilityManager SkillManager(play2, holder, manager2);
//     // SkillManager.activateAbility(response);
//     // response.GetAbilityResult();
//     // SkillManager.activateAbility(response);
//     // response.GetAbilityResult();
//     // SkillManager.activateAbility(response);
//     // response.GetAbilityResult();

//     // play2.attack(9, 9);
//     // play2.attack(9, 9);
//     // if (play2.getCell(9, 9).getShip()->getIsDesrtoyed()){
//     //     SkillManager.addRandomAbility();
//     // }
//     // SkillManager.activateAbility(response);
//     // response.GetAbilityResult();
//     // play1.drawField();
//     // play2.drawField();
        
//     int h = 10;
//     int w = 10;
//     std::vector<int> sizes = {4, 3};
//     GameStatePlayer player(w, h, sizes, response);
//     GameStateEnemy enemy(w, h, sizes);
//     GameManager gameManager(player, enemy);
//     gameManager.setGameStatus(GameStatus::MENU);
//     gameManager.startNewGame();
//     gameManager.getGameStatePlayer().getGameField().drawField(1);
//     gameManager.getGameStateEnemy().getGameField().drawField(1);
//     // gameManager.getGameStateEnemy().getGameField().attack(1, 1, 1);
//     // gameManager.getGameStateEnemy().getGameField().attack(2, 1, 1);
//     // gameManager.getGameStateEnemy().getGameField().attack(3, 1, 1);
//     // gameManager.getGameStateEnemy().getGameField().attack(4, 1, 1);
//     gameManager.move(1, 1);
//     gameManager.getGameStatePlayer().getGameField().drawField(1);
//     gameManager.getGameStateEnemy().getGameField().drawField(1);
// }

int main()
{
    int h = 10;
    int w = 10;
    std::vector<int> sizes = {4};
    GameStatePlayer player = GameStatePlayer(w, h, sizes);
    GameStateEnemy enemy = GameStateEnemy(w, h, sizes);
    GameManager gameManager(player, enemy);
    gameManager.setGameStatus(GameStatus::MENU);
    // gameManager.startNewGame();
    // gameManager.move(1, 1);
    // gameManager.applyAbility();
    // gameManager.getGameStatePlayer().getGameField().drawField(1);
    // gameManager.getGameStateEnemy().getGameField().drawField(1);

    // gameManager.save("player", "enemy");
    // gameManager.save("player", "enemy");
    // gameManager.save("player", "enemy");
    // gameManager.save("player", "enemy");
    // GameStatePlayer newplayer = GameStatePlayer();
    // GameStateEnemy newenemy = GameStateEnemy();
    // GameManager game(newplayer, newenemy);
    // game.load("player", "enemy");
    // std::cout << "================================\n";
    // newplayer.getGameField().drawField(1);
    // newenemy.getGameField().drawField(1);
    // game.applyAbility();
    handleInput(gameManager);
    // gameManager.move(1, 1);
    // gameManager.move(1, 1);
    // gameManager.move(2, 2);
    // player.getGameField().drawField(1);
    // enemy.getGameField().drawField(1);
    // gameManager.getGameStateEnemy().reset();
    // enemy.getGameField().drawField(1);
    return 0;
}