#pragma once
#include "Human.h"
#include "Computer.h"
#include <iostream>

class Game
{
private:
	std::shared_ptr<Human> human;
	std::shared_ptr<Computer> computer;
	int winCount;
	void displayMove(const std::string& playerName, Move move);
	void checkWinner(Move humanMove, Move computerMove);
	void showScore() const;

public:
	Game(std::shared_ptr<Human> human, std::shared_ptr<Computer> computer);
	Game(std::shared_ptr<Human> human, std::shared_ptr<Computer> computer, int winRounds);
	void play(bool isTestMode);
};

