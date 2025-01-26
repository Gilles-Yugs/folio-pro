#include "Computer.h"
#include <ctime>
#include <random>

Move Computer::getMove()
{
	static std::random_device rd;
	static std::mt19937 gen(rd());
	static std::uniform_int_distribution<int> dist(1, 3);
	return static_cast<Move>(dist(gen));
}