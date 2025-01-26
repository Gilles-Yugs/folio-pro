#include "Game.h"
#include "Test.h"

class GameManager
{
private:
	// Instances of Human and Computer players
	std::shared_ptr<Human> human;
	std::shared_ptr<Computer> computer;

	// Number of victories required to win
	int winCount;

public:
	void run();
	void test();
	GameManager();
};

