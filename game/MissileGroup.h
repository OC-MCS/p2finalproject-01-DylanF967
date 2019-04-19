#pragma once


#include <iostream>

#include <SFML/Graphics.hpp>
using namespace sf;
#include "GameUI.h"
#include "GameManager.h"
#include "Missile.h"
#include <list>
#include "AlienShip.h"
#include "GroupofAliens.h"

using namespace std;

//This is the class for a group of missiles, it class all of the functions in the missile class but does it for every missile in the list

class MissileGroup
{
	private:

		list<Missile> Missiles;

	public:

		MissileGroup(Texture &Appearance, int XPos, int YPos)
		{
			Missile missile(Appearance, XPos, YPos);
			Missiles.push_back(missile);

		}

		void DrawMissiles(RenderWindow &win)
		{
			list<Missile> ::iterator iter;

			for (iter = Missiles.begin(); iter != Missiles.end(); iter++)
			{
				(*iter).draw(win);
			}
		}

		void MoveMissiles()
		{
			list<Missile> ::iterator iter;
			float MoveDist = 2;
			for (iter = Missiles.begin(); iter != Missiles.end(); iter++)
			{
				(*iter).Move(MoveDist);
			}
		}

		void AddMissile(Texture &Appearance, int XPos, int YPos)
		{
			
			
			Missile missile(Appearance, XPos, YPos);
			
			Missiles.push_back(missile);
			
		}

		void MissileHit(AlienGroup Passed)
		{
			list<Missile> ::iterator iter;

			for (iter = Missiles.begin(); iter != Missiles.end(); iter++)
			{
				(*iter).Hit(Passed);
			}
		}
};