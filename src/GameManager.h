#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "modules.h"
#include "GameStatePlayer.h"
#include "GameStateEnemy.h"
#include "ShipPlacer.h"
enum GameStatus
{
    MENU,
    SHIP_PLACEMENT,
    GAME,
    ABILITY,
    WIN,
    LOSE,
    PAUSE,
    EXIT 
};

class GameManager {
private:
    GameStatePlayer& gameStatePlayer;
    GameStateEnemy& gameStateEnemy;
    GameStatus gameStatus;
public:
    GameManager(GameStatePlayer& gameStatePlayer, GameStateEnemy& gameStateEnemy): gameStatePlayer(gameStatePlayer), gameStateEnemy(gameStateEnemy) {};

    void startNewGame();

    bool isGameStatus(GameStatus gameStatus_);

    void lose();

    void backToMenu();

    void goToNextLevel();

    void continueGame();

    void attack(int x, int y);

    void applyAbility();

    void move(int x, int y);

    void checkGameOutCome();

    GameStatus getStatus();

    void pause();

    void setGameStatus(GameStatus gameStatus_);

    void exitGame();

    GameStatePlayer &getGameStatePlayer();

    GameStateEnemy &getGameStateEnemy();

    void save(std::string name1, std::string name2);

    void load(std::string name1, std::string name2);
};

#endif