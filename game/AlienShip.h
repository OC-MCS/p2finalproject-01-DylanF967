#pragma once
#include <iostream>
using namespace std;
#include <SFML/Graphics.hpp>
using namespace sf;


// The base class for one alien that draws, moves, creates, and so on.
class Alien
{
	private:
		

		Sprite AlienSpr;


	public:

	

		Alien(Texture &Appearance)
		{
			
			AlienSpr.setTexture(Appearance);
			AlienSpr.setPosition(100, 200);
			AlienSpr.setScale(.25, .25);
			AlienSpr.setRotation(180);
			

			
		}

		void draw(RenderWindow &win)
		{
			win.draw(AlienSpr);

		}

		void SetPst(float x, float y)
		{
			AlienSpr.setPosition(x, y);

		}

		void Move(float MoveDist)
		{
			AlienSpr.move(0, MoveDist);

		}

		Vector2f GetPosition()
		{
			return AlienSpr.getPosition();

		}

		bool ReachedPlayer()
		{
			bool Madeit = false;
			if (AlienSpr.getPosition().y == 800);
			{
				Madeit = true;
			}

			return Madeit;
		}
};