#include "GameManager.h"

GameManager::GameManager()
{
	human = std::make_shared<Human>("Player 1");
	computer = std::make_shared<Computer>("AI");
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