/************************************************************************
Program Name: Creature tournament
Author:		  Robert Boespflug
Date:		  05/29/2017
Description:  This is the Vampire class function header file.
*************************************************************************/

#pragma once

#include "Creature.hpp"
class Vampire : public Creature
{
public:
	Vampire();
	virtual int attack() override;
	virtual int defense() override; 

	const int MAX_SIDES_ATTACK = 12;
	const int MIN_SIDES_ATTACK = 1;
	const int MAX_SIDES_DEFENSE = 6;
	const int MIN_SIDES_DEFENSE = 1;
};

