#pragma once
#include "Player.h"

class Computer : public Player
{
public:
	explicit Computer(const std::string& playerName) : Player(playerName) {};
	Move getMove() override;
};

