
#include "GameManager.h"
#include "TempInput.h"



int main()
{
    int h = 10;
    int w = 10;
    std::vector<int> sizes = {4};
    GameStatePlayer player = GameStatePlayer(w, h, sizes);
    GameStateEnemy enemy = GameStateEnemy(w, h, sizes);
    GameManager gameManager(player, enemy);
    gameManager.setGameStatus(GameStatus::MENU);
    handleInput(gameManager);
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
    // gameManager.move(1, 1);
    // gameManager.move(1, 1);
    // gameManager.move(2, 2);
    // player.getGameField().drawField(1);
    // enemy.getGameField().drawField(1);
    // gameManager.getGameStateEnemy().reset();
    // enemy.getGameField().drawField(1);
    return 0;
}