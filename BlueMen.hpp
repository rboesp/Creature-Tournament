/************************************************************************
Program Name: Creature tournament
Author:		  Robert Boespflug
Date:		  05/29/2017
Description:  This is the BlueMen class function header file.
*************************************************************************/

#pragma once

#include "Creature.hpp"

/*********************************************************************
** Description: This is the BlueMen class. This class represents the
Blue Men creature in the creature fight program.
**********************************************************************/
class BlueMen : public Creature
{
public:
	BlueMen();
	virtual int attack() override;
	virtual int defense() override;

	const int MAX_SIDES_ATTACK = 10;
	const int MIN_SIDES_ATTACK = 1;
	const int MAX_SIDES_DEFENSE = 6;
	const int MIN_SIDES_DEFENSE = 1;
};
