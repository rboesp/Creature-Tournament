/************************************************************************
Program Name: Creature tournament
Author:		  Robert Boespflug
Date:		  05/29/2017
Description:  This is the Creature class function header file.
*************************************************************************/

#pragma once

/********************************************************
** Description: This is the pure virtual Creature class. 
* This pure virtual class has two pure virtual functions
* attack and defense that are common to all creatures.
********************************************************/

#include "creatureMenu.hpp"
#include <math.h>


class Creature
{

protected: 
	virtual int attack() = 0;
	virtual int defense() = 0;
	int armor_points;
	int strength_points;

public:
	Creature();
	virtual ~Creature();
	
	Creature* creatureFight(Creature * creature1, Creature * creature2);
	
	//RECOVER HEALTH function after creature fights and wins
	void recoverHealth(); 

	const int CHARM = -1;
	const int DEAD = 0;
	const int CREATURE_ONE = 1;
	const int CREATURE_TWO = 2;
	const int NO_DAMAGE = 0;
	const int RESTORE_POINTS = 5;
};
