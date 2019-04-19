#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;
#include "GameManager.h"



// finish this code; add functions, data as needed
//This is what draws the words start and lives as well as the button in the same place as start so it just looks like you are clicking start.

class GameUI
{
private:
	int Lives;
	RectangleShape squareBtn;

public:

	GameUI(GameMgr *mgr)
	{
		Lives = mgr->GetLives();
	}
	void draw(RenderWindow& win)
	{


		Font font;
		if (!font.loadFromFile("C:\\Windows\\Fonts\\arial.ttf"))
		{

		}

		// title
		Text title("Lives:", font, 25);
		
		title.setPosition(20, 550);
		win.draw(title);
	}

	void Start(RenderWindow &win)
	{
		
		Font font;
		if (!font.loadFromFile("C:\\Windows\\Fonts\\arial.ttf"))
		{

		}

		squareBtn.setPosition(350, 300);
		squareBtn.setSize(Vector2f(100, 100));
		Text start("START", font, 30);
		start.setPosition(350, 300);
		win.draw(start);
	}

	bool handleMouseUp(Vector2f mouse, GameMgr *mgr)
	{

		cout << "You have clicked." << endl;
		if (squareBtn.getGlobalBounds().contains(mouse)) // mouse is a vector2f
	// mouse is currently over SquareBtn
		{
			cout << "Game Started." << endl;
			return true;
		}
	}
};