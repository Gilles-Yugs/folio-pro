#include "Moves.h"

void Moves::setMoves(int moveNumber)
{
	randomNum = moveNumber;
}

Player::move Moves::getMoves()
{
	switch (randomNum)
	{
	case 1:
		return Player::move::paper;
		break;
	case 2:
		return Player::move::scissors;
	case 3:
		return Player::move::stone;
	}
	return Player::move::paper; // Default case (won't be reached but ensures no undefined behavior)
}