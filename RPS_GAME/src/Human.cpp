#include "Human.h"

Move Human::getMove()
{
	int input;
	while (true)
	{
		std::cout << "\nEnter your move (1 for Paper, 2 for Scissors, 3 for Stone): ";
		std::cin >> input;
		if (input >= 1 && input <= 3)
		{
			std::cout << "Valid move.\n";
			return static_cast<Move>(input);
		}
		else
		{
			std::cout << "Invalid move! Try again.\n";
		}
	}
}