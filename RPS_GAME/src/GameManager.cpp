#include "GameManager.h"

GameManager::GameManager()
{
	std::cout << "Enter the name of the human player: ";
	std::cin >> humanName;
	std::cout << "Enter the name of the computer player: ";
	std::cin >> computerName;
	human = std::make_shared<Human>(humanName);
	computer = std::make_shared<Computer>(computerName);
	winCount = 3;
}

void GameManager::run()
{
	// Create the Game instance
	Game game(human, computer, winCount);
	// Start the game
	game.play(false);
}

void GameManager::test()
{
	Test& test = Test::getInstance();
	test.testPlayerClass();
	test.testComputerMoveGeneration();
	test.testHumanMoveGeneration();
	test.testGameLogic();
	test.testInvalidInput();
}