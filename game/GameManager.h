#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;


//This class manages the lives and it would manage the score if I got to that point.

class GameMgr
{
private:

	int Lives;

public:
	GameMgr(int StartingLives)
	{
		Lives = StartingLives;
	}

	int GetLives()
	{
		return Lives;
	}

	void RemoveLife()
	{
		Lives - 1;
	}
};