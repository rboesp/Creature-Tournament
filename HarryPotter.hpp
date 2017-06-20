/*******************************************************************
Program Name: Creature tournament
Author:		  Robert Boespflug
Date:		  05/29/2017
Description:  This is the HarryPotter class function header file.
*******************************************************************/

#pragma once

#include "Creature.hpp"

class HarryPotter : public Creature
{
public:
	HarryPotter();
	virtual ~HarryPotter() override;

	virtual int attack() override;
	virtual int defense() override;

	const int MAX_SIDES = 6;
	const int MIN_SIDES = 1;
	const int SECOND_LIFE_STRENGTH = 20;
	bool firstLife = true;
};

