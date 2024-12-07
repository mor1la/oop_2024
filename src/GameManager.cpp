#include "GameManager.h"

GameStatePlayer &GameManager::getGameStatePlayer(){
    return gameStatePlayer;
}

GameStateEnemy &GameManager::getGameStateEnemy(){
    return gameStateEnemy;
}

void GameManager::save(std::string name1, std::string name2){
    if (isGameStatus(GameStatus::PAUSE)){
        gameStatePlayer.save(name1);
        gameStateEnemy.save(name2);
    }
}

void GameManager::load(std::string name1, std::string name2){
    gameStatePlayer.load(name1);
    gameStateEnemy.load(name2);
    setGameStatus(GameStatus::GAME);
}

GameStatus GameManager::getStatus(){
    return gameStatus;
}

bool GameManager::isGameStatus(GameStatus gameStatus_){
    return gameStatus == gameStatus_;
}

void GameManager::startNewGame()
{
    if (isGameStatus(GameStatus::MENU)){
        gameStatePlayer.reset();
        gameStateEnemy.reset();
        gameStatus = GameStatus::SHIP_PLACEMENT;
        ShipPlacer::placeShipsForEnemy(
            gameStateEnemy.getGameField(),
            gameStateEnemy.getShipManager());

        ShipPlacer::placeShipsForPlayer(
            gameStatePlayer.getGameField(),
            gameStatePlayer.getShipManager(),
            gameStatePlayer.getCoordHolder()); 

        gameStatePlayer.setNeedNewField(false);
        gameStatus = GameStatus::GAME;    
    }
}

void GameManager::lose(){
    if (isGameStatus(GameStatus::LOSE)){
        gameStatus = GameStatus::MENU;
    }
}

void GameManager::goToNextLevel(){
    if (isGameStatus(GameStatus::WIN)){
        gameStateEnemy.reset();
        ShipPlacer::placeShipsForEnemy(
            gameStateEnemy.getGameField(),
            gameStateEnemy.getShipManager()); 
        gameStatus = GameStatus::GAME;  
    }
}

void GameManager::continueGame(){
    if (isGameStatus(GameStatus::MENU) && gameStatePlayer.getNeedNewField() == false){
        gameStatus = GameStatus::GAME;
    }
}

void GameManager::backToMenu(){
    if (isGameStatus(GameStatus::PAUSE)){
        gameStatus = GameStatus::MENU;
    }
}

void GameManager::attack(int x, int y){
    if (gameStatePlayer.getAbilityResponse().getIsDoubleDamageActivated() && gameStatePlayer.getGameField().checkCoordinateForAttack(x, y)){
        gameStateEnemy.getGameField().attack(x, y, 2);
        gameStatePlayer.getAbilityResponse().setIsDoubleDamageActivated(false);
    }else{              
        gameStateEnemy.getGameField().attack(x, y, 1);
    }

    if (gameStateEnemy.getGameField().getCell(x, y).getShip() && gameStateEnemy.getGameField().getCell(x, y).getShip()->getIsDesrtoyed()){
        gameStatePlayer.getAbilityManager().addRandomAbility();
    } 
}

void GameManager::applyAbility(){
    gameStatePlayer.getAbilityManager().activateAbility(gameStatePlayer.getAbilityResponse());
    gameStatePlayer.getAbilityResponse().GetAbilityResult();
    checkGameOutCome();
}

void GameManager::move(int x, int y){
    if (isGameStatus(GameStatus::GAME)){
        attack(x, y);
        checkGameOutCome();
    }

    if (isGameStatus(GameStatus::GAME)){
        gameStatePlayer.getGameField().randomAttack();
        checkGameOutCome();
    }
}

//pause: MENU SAVE CONTINUE

void GameManager::checkGameOutCome(){
    if (isGameStatus(GameStatus::GAME)){
        if (gameStateEnemy.getShipManager().areAllShipsDestroyed()){
            gameStatus = GameStatus::WIN;
            gameStatePlayer.setNumberOfWins();
        }else if (gameStatePlayer.getShipManager().areAllShipsDestroyed()){
            gameStatus = GameStatus::LOSE;
            gameStatePlayer.setNeedNewField(true);
        }
    }
}

void GameManager::pause(){
    if (isGameStatus(GameStatus::GAME)){
        gameStatus = GameStatus::PAUSE;
    }else if (isGameStatus(GameStatus::PAUSE)){
        gameStatus = GameStatus::GAME;//backtomenu
    }
}

void GameManager::setGameStatus(GameStatus gameStatus_){
    gameStatus = gameStatus_;
}

void GameManager::exitGame(){
    if (isGameStatus(GameStatus::MENU)){
        gameStatus = GameStatus::EXIT;
    }
}