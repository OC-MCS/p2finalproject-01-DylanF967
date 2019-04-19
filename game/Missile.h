#pragma once

#pragma once
#include <iostream>
using namespace std;
#include <SFML/Graphics.hpp>
using namespace sf;
#include "AlienShip.h"
#include "GroupofAliens.h"

// The class for the missiles that creates a Missile Sprite and draws it on the window as well as moves it.
// This is also where the detect if missiles hit the aliens would be located
class Missile
{
	private:
		Sprite MissileSpr;

	public:

		Missile(Texture &Appearance, int XPos, int YPos)
		{
			MissileSpr.setTexture(Appearance);
			MissileSpr.setPosition(XPos, YPos + 5);

		}

		void draw(RenderWindow &win)
		{
			win.draw(MissileSpr);

		}

		void Move(float MoveDist)
		{
			MissileSpr.move(0, 10);
		}

		void Hit(AlienGroup Passed)
		{
			list<Alien> ::iterator iter;

			//if (MissileSpr.getPosition() == Passed.GetPosition());
		}
};