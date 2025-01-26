#pragma once
#include "Player.h"
#include <iostream>

class Human : public Player
{
public:
	explicit Human(const std::string& playerName) : Player(playerName) {}
	Move getMove() override;
};

