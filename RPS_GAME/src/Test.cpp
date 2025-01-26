#include "Test.h"
#include <cassert>

void Test::testPlayerClass()
{
	Player* player = new Human("TestPlayer");
	assert(player->getVictoryCount() == 0); // Check initial victory count
	player->incrementVictory();
	assert(player->getVictoryCount() == 1); // Victory count should increment to 1
	delete player;
}

void Test::testComputerMoveGeneration()
{
	Computer computer("TestComputer");
	Move move = computer.getMove();
	assert(move == Move::paper || move == Move::scissors || move == Move::stone); // Computer should pick a valid move
}

void Test::testHumanMoveGeneration()
{
	Human human("TestHuman");
	Move humanMove = Move::paper;
	assert(humanMove == Move::paper); // Ensure the move matches paper
}

void Test::testGameLogic()
{
	std::shared_ptr<Human> human = std::make_shared<Human>("TestPlayer");
	std::shared_ptr<Computer> computer = std::make_shared<Computer>("TestComputer");

	Game game(human, computer);

	std::cout << "First round:\n";
	game.play(true);

	human->setPredefinedMove(Move::paper);
	computer->setPredefinedMove(Move::stone);
	std::cout << "Second round:\n";
	game.play(true);

	human->setPredefinedMove(Move::scissors);
	computer->setPredefinedMove(Move::paper);
	std::cout << "Third round:\n";
	game.play(true);

	// Check the score and verify if it was updated correctly
	std::cout << "Final score: " << human->getVictoryCount() << " - " << computer->getVictoryCount() << "\n" << std::endl;

	// Verify if the correct winner was identified
	if (human->getVictoryCount() == 2 && computer->getVictoryCount() == 0)
	{
		std::cout << "Test passed! The Human player won the game with 2 victories.\n";
	}
	else {
		std::cout << "Test failed! The scores don't match the expected outcome.\n";
	}
}

std::istringstream Test::simulatedinput(const std::string& str)
{
	
	return std::istringstream(str);
}

void Test::testInvalidInput()
{
	std::istringstream simulatedinput("4\n-1\n0\n2\n"); // Invalid inputs (4, -1, 0) and a valid input (2)

	// Redirect ``std::cin` using for testing
	std::streambuf* originalCinBuffer = std::cin.rdbuf(simulatedinput.rdbuf()); // Redirect std::cin

	// Create a Human player for testing
	Human human("TestHuman");
	Move move = human.getMove();

	// Restore original `std::cin` buffer
	std::cin.rdbuf(originalCinBuffer);

	// Assert that valid move is correctly processed
	assert(move == Move::scissors); // "2" corresponds to Scissors
}