#pragma once


#include <iostream>

#include <SFML/Graphics.hpp>
using namespace sf;
#include "GameUI.h"
#include "GameManager.h"
#include "AlienShip.h"
#include "GroupofAliens.h"
#include <list>


using namespace std;


//Calls all the functions for the Alien class but does it for every Alien in the group. 
class AlienGroup
{

private:
	list<Alien> Army;
	
	int Number;


public:

	

	AlienGroup(int Amount, Texture &Appearance, int Spacing)
	{
		for (int x = 0; x < Amount; x++)
		{
			
			Number = Amount;
			Alien Enemy(Appearance);
			Enemy.SetPst(Spacing, 100);
			Army.push_back(Enemy);
			Spacing = Spacing + 75;
		
		}
	}

	void DrawArmy(RenderWindow &win)
	{
		//cout << "I DID NOT CRASH!" << endl;
		list<Alien> ::iterator iter;
		
		
		for (iter = Army.begin(); iter != Army.end(); iter++)
		{
			(*iter).draw(win);

		}
	}

	void MoveAliens()
	{
		list<Alien> ::iterator iter;
		float MoveDist = .5;
		for (iter = Army.begin(); iter != Army.end(); iter++)
		{
			(*iter).Move(MoveDist);
		}
	}

	void GetPosition()
	{
		list<Alien> ::iterator iter;

		for (iter = Army.begin(); iter != Army.end(); iter++)
		{
			(*iter).GetPosition();
			
		}
	}

	bool ReachedPlayer()
	{
		list<Alien> ::iterator iter;
		bool OneMadeIt = false;
		for (iter = Army.begin(); iter != Army.end() && OneMadeIt == false; iter++ );
		{
			OneMadeIt = (*iter).ReachedPlayer();
			
			
		}
		return OneMadeIt;
	}
};