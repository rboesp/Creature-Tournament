/************************************************************************
Program Name: Creature tournament
Author:		  Robert Boespflug
Date:		  05/29/2017
Description:  This is the Barbarian class function header file.
*************************************************************************/

#pragma once

#include "Creature.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

using std::cout;
using std::cin;
using std::endl;


/**************************************************************
** Description: This is the Barbarian derived class. This class
* is derived from the abstract Creature class. This class 
* represents a Barbarian creature in the creature tournament game.
***************************************************************/
class Barbarian : public Creature
{
private:
	const int MAX_SIDES = 6;
	const int MIN_SIDES = 1;

public:
	Barbarian();
	virtual int attack() override;
	virtual int defense() override; 
};