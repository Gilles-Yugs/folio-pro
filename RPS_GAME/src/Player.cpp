#include "Player.h"

Player::Player(const std::string& playerName) : name(playerName), victoryCount(0), predefinedMove(Move::stone)
{}

void Player::incrementVictory()
{
	++victoryCount;
}

int Player::getVictoryCount() const
{
	return victoryCount;
}

std::string Player::getName() const
{
	return name;
}
void Player::setPredefinedMove(const Move& move)
{
	predefinedMove = move;
}

Move Player::getPredefinedMove() const
{
	return predefinedMove;
}