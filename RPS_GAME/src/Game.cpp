#include "Game.h"

Game::Game(std::shared_ptr<Human> human, std::shared_ptr<Computer> computer) :
	human(human), computer(computer)
{}

Game::Game(std::shared_ptr<Human> human, std::shared_ptr<Computer> computer, int winRounds) : 
	human(human), computer(computer), winCount(winRounds)
{}

void Game::displayMove(const std::string& playerName, Move move)
{
	std::cout << playerName << " chose ";
	switch (move)
	{
	case Move::paper: 
		std::cout << "Paper"; 
		break;
	case Move::scissors: 
		std::cout << "Scissors";
		break;
	case Move::stone: 
		std::cout << "Stone";
		break;
	}
	std::cout << ".\n";
}

void Game::checkWinner(Move humanMove, Move computerMove)
{
	if (humanMove == computerMove)
	{
		std::cout << "It's a tie!\n";
	}
	else if ((humanMove == Move::paper && computerMove == Move::stone) ||
		(humanMove == Move::scissors && computerMove == Move::paper) ||
		(humanMove == Move::stone && computerMove == Move::scissors))
	{
		std::cout << "You win this round!\n";
		human->incrementVictory();
	}
	else
	{
		std::cout << "Computer wins this round!\n";
		computer->incrementVictory();
	}
}

void Game::showScore() const
{
	std::cout << "\nScore: " << human->getName() << " " << human->getVictoryCount()
		<< " - " << computer->getVictoryCount() << " " << computer->getName() << "\n";
}

void Game::play(bool isTestMode)
{
	std::cout << "Welcome to Stone-Paper-Scissors!\n";
	if (!isTestMode) {
		std::cout << "First to " << winCount << " victories wins the game.\n";
		std::cout << "Enter the number of victories required to win (default is 3): ";
		std::cin >> winCount;
	}

	while (isTestMode || (human->getVictoryCount() < winCount && computer->getVictoryCount() < winCount))
	{
		Move humanMove = isTestMode ? human->getPredefinedMove() : human->getMove();
		Move computerMove = isTestMode ? computer->getPredefinedMove() : computer->getMove();

		displayMove(human->getName(), humanMove);
		displayMove(computer->getName(), computerMove);

		checkWinner(humanMove, computerMove);
		showScore();

		if (isTestMode) break;
	}

	if (!isTestMode)
	{
		if (human->getVictoryCount() > computer->getVictoryCount())
		{
			std::cout << "\nCongratulations! You win the game!\n";
		}
		else
		{
			std::cout << "\nThe computer wins the game. Better luck next time!\n";
		}
	}
}
