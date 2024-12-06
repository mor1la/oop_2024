
#include "TempInput.h"

void handleInput(GameManager& gameManager) {

    while (true) {

        if (gameManager.isGameStatus(GameStatus::MENU)) {
            std::cout << "=== Main Menu ===" << std::endl;
            std::cout << "[N] New Game" << std::endl;
            std::cout << "[L] Load Game" << std::endl;
            std::cout << "[Q] Quit" << std::endl;
        } else if (gameManager.isGameStatus(GameStatus::GAME)) {
            std::cout << "=== In Game ===" << std::endl;
            std::cout << "[A] Attack" << std::endl;
            std::cout << "[P] Pause" << std::endl;
            std::cout << "[U] Use Ability" << std::endl;
            std::cout << "[M] Quit to Main Menu" << std::endl;
        }
        char input = _getch();

        switch (input) {
        case 'N':
        case 'n':
            std::cout << "New game started." << std::endl;                       
            gameManager.startNewGame();
            clearConsole();
            std::cout << "Player Field" << std::endl;
            gameManager.getGameStatePlayer().getGameField().drawField(true);
            std::cout << "Enemy Field" << std::endl;
            gameManager.getGameStateEnemy().getGameField().drawField(true);
            break;
        case 'C':
        case 'c':
            gameManager.continueGame();
            std::cout << "Continuing game." << std::endl;
            break;
        case 'S':
        case 's': {
            std::string savePlayer = "player";
            std::string saveEnemy = "enemy";
            gameManager.save(savePlayer, saveEnemy);
            std::cout << "Game saved to " << savePlayer << " and " << saveEnemy << "." << std::endl;
            break;
        }
        case 'L':
        case 'l': {
            std::string loadPlayer = "player";
            std::string loadEnemy = "enemy";
            gameManager.load(loadPlayer, loadEnemy);
            std::cout << "Game loaded from " << loadPlayer << " and " << loadEnemy << "." << std::endl;
            break;
        }
        case 'P':
        case 'p':
            gameManager.pause();
            std::cout << "Game paused/unpaused." << std::endl;
            break;
        case 'M':
        case 'm':
            gameManager.backToMenu();
            std::cout << "Returned to menu." << std::endl;
            break;
        case 'U':
        case 'u':
            std::cout << "Ability used." << std::endl;
            gameManager.applyAbility();
            gameManager.getGameStatePlayer().getAbilityResponse().GetAbilityResult();
            std::cout << "Player Field" << std::endl;
            gameManager.getGameStatePlayer().getGameField().drawField(true);
            std::cout << "Enemy Field" << std::endl;
            gameManager.getGameStateEnemy().getGameField().drawField(true);
            break;
        case 'A':
        case 'a': {
            bool success = false;
            do {
                int x, y;
                std::cout << "Enter attack coordinates (x y): ";
                std::cin >> x >> y;

                success =  gameManager.getGameStateEnemy().getGameField().getCell(x, y).isAttackable();
                if (!success) {
                    std::cout << "Invalid coordinates or attack not possible. Try again." << std::endl;
                }else{
                    gameManager.attack(x, y);
                }
            } while (!success);
            std::cout << "Player Field" << std::endl;
            gameManager.getGameStatePlayer().getGameField().drawField(true);
            std::cout << "Enemy Field" << std::endl;
            gameManager.getGameStateEnemy().getGameField().drawField(true);
            std::cout << "Attack successful!" << std::endl;
            break;
        }
        case 'Q':
        case 'q':
            std::cout << "Quitting game..." << std::endl;
            return;
        default:
            std::cout << "Unknown command: " << input << std::endl;
        }
    }
}
