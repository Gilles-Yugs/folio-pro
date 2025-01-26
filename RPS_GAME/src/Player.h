#pragma once
#include <string>

enum class Move {
	paper = 1,
	scissors = 2,
	stone = 3
};

// Abstract Base Class for Player
class Player
{
protected:
	std::string name;
	int victoryCount;
	Move predefinedMove;

public:
	explicit Player(const std::string& playerName);
	virtual Move getMove() = 0; // Function for move generation
	void incrementVictory();
	int getVictoryCount() const;
	std::string getName() const;
	void setPredefinedMove(const Move& move);
	Move getPredefinedMove() const;
	virtual ~Player() = default;
};

