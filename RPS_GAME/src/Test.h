#pragma once
#include "Human.h"
#include "Computer.h"
#include "Game.h"
#include <assert.h>

#include <sstream>

class Test
{
public:
	Test() = default;
	static Test& getInstance()
	{
		static Test instance;
		return instance;
	}
	
	void testPlayerClass();
	void testComputerMoveGeneration();
	void testHumanMoveGeneration();
	void testGameLogic();
	void testInvalidInput();

private:
	// Function to simulate input stream with invalid and valid inputs
	std::istringstream simulatedinput(const std::string& str);
	std::shared_ptr<Human> human;
	std::shared_ptr<Computer> computer;
};