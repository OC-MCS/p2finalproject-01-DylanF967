//=========================================================
// This is just the starting point for your final project.
// You are expected to modify and add classes/files as needed.
// The code below is the original code for our first graphics
// project (moving the little green ship). 
//========================================================
#include <iostream>
using namespace std;
#include <SFML/Graphics.hpp>
using namespace sf; 
#include "GameUI.h"
#include "GameManager.h"
#include "AlienShip.h"
#include "GroupofAliens.h"
#include "Missile.h"
#include "MissileGroup.h"
#include <list>

//============================================================
// YOUR HEADER WITH YOUR NAME GOES HERE. PLEASE DO NOT FORGET THIS
// Dylan Fortney
// Final Project
// 4/19/2019

//============================================================

// note: a Sprite represents an image on screen. A sprite knows and remembers its own position
// ship.move(offsetX, offsetY) adds offsetX, offsetY to 
// the current position of the ship. 
// x is horizontal, y is vertical. 
// 0,0 is in the UPPER LEFT of the screen, y increases DOWN the screen
void moveShip(Sprite& ship)
{
	const float DISTANCE = 5.0;
	float shipX = ship.getPosition().x;
	

	if (Keyboard::isKeyPressed(Keyboard::Left) && shipX > 0)
	{
		// left arrow is pressed: move our ship left 5 pixels
		// 2nd parm is y direction. We don't want to move up/down, so it's zero.
		ship.move(-DISTANCE, 0);
	}
	else if (Keyboard::isKeyPressed(Keyboard::Right) && shipX < 780)
	{
		// right arrow is pressed: move our ship right 5 pixels
		ship.move(DISTANCE, 0);
	}
}



int main()
{
	int StartingLives = 3;
	const int WINDOW_WIDTH = 800;
	const int WINDOW_HEIGHT = 600;
	GameMgr System(StartingLives);
	GameUI  GAME(&System);
	

	
	RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "aliens!");
	// Limit the framerate to 60 frames per second
	window.setFramerateLimit(60);
	
	
	// load textures from file into memory. This doesn't display anything yet.
	// Notice we do this *before* going into animation loop.
	Texture shipTexture;
	if (!shipTexture.loadFromFile("ship.png"))
	{
		cout << "Unable to load ship texture!" << endl;
		exit(EXIT_FAILURE);
	}
	Texture starsTexture;
	if (!starsTexture.loadFromFile("stars.jpg"))
	{
		cout << "Unable to load stars texture!" << endl;
		exit(EXIT_FAILURE);
	}

	Texture MissileTexture;
	if (!MissileTexture.loadFromFile("missile.png"))
	{
		cout << "Unable to load missile texture." << endl;
		exit(EXIT_FAILURE);
	}
	Texture AlienShip1;
	if (!AlienShip1.loadFromFile("AlienShip.png"))
	{
		cout << "Failed to load Alien texture." << endl;
		exit(EXIT_FAILURE);
	}


	//Alien EnemyShip1(AlienShip1);
	AlienGroup Group1(10, AlienShip1, 100);

	

	// A sprite is a thing we can draw and manipulate on the screen.
	// We have to give it a "texture" to specify what it looks like

	Sprite background;
	background.setTexture(starsTexture);
	// The texture file is 640x480, so scale it up a little to cover 800x600 window
	background.setScale(1.5, 1.5);

	// create sprite and texture it
	Sprite ship;
	ship.setTexture(shipTexture);

	
	// initial position of the ship will be approx middle of screen
	float shipX = 400;
	float shipY = 500;
	ship.setPosition(shipX, shipY);

	
	
	bool MissileInFlight = false;
	bool GameStarted = false;
	while (window.isOpen())
	{
		// check all the window's events that were triggered since the last iteration of the loop
		// For now, we just need this so we can click on the window and close it
		Event event;
		MissileGroup MissilesFired(MissileTexture, ship.getPosition().x, ship.getPosition().y);

		

		while (window.pollEvent(event))
		{
			// "close requested" event: we close the window
			
			if (event.type == Event::Closed)
			{
				window.close();
			}

			else if (event.type == Event::MouseButtonReleased)
			{
				// maybe they just clicked on one of the settings "buttons"
				// check for this and handle it.
				Vector2f mousePos = window.mapPixelToCoords(Mouse::getPosition(window));
				GameStarted = GAME.handleMouseUp(mousePos, &System);
			}
			else if (event.type == Event::MouseMoved && Mouse::isButtonPressed(Mouse::Button::Left))
			{

				Vector2f mousePos = window.mapPixelToCoords(Mouse::getPosition(window));
			
			}
			
			else if (event.type == Event::KeyPressed)
			{
				if (event.key.code == Keyboard::Space)
				{
					// handle space bar
					cout << "Missile Fired." << endl;
					MissilesFired.AddMissile(MissileTexture, ship.getPosition().x, ship.getPosition().y);

					MissileInFlight = true;
				}
				
			}

			
			
		}

		

		//===========================================================
		// Everything from here to the end of the loop is where you put your
		// code to produce ONE frame of the animation. The next iteration of the loop will
		// render the next frame, and so on. All this happens ~ 60 times/second.
		//===========================================================

		// draw background first, so everything that's drawn later 
		// will appear on top of background
		window.draw(background);
		if (GameStarted == true)
		{


			if (MissileInFlight == true)
			{
				MissilesFired.MoveMissiles();
				MissilesFired.DrawMissiles(window);

			}
			moveShip(ship);
			Group1.MoveAliens();
			// draw the ship on top of background 
			// (the ship from previous frame was erased when we drew background)
			window.draw(ship);
			GAME.draw(window);



			Group1.DrawArmy(window);
			MissilesFired.MissileHit(Group1);


			//This is the code for calling the function to see if the aliens have reached the player

			/*if (Group1.ReachedPlayer() == true)
			{
				System.RemoveLife();
			}*/
		}

		else
		{
			GAME.Start(window);
		}

		//EnemyShip1.draw(window);
		// end the current frame; this makes everything that we have 
		// already "drawn" actually show up on the screen
		window.display();

		// At this point the frame we have built is now visible on screen.
		// Now control will go back to the top of the animation loop
		// to build the next frame. Since we begin by drawing the
		// background, each frame is rebuilt from scratch.

	} // end body of animation loop

	return 0;
}

