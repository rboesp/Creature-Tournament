/*******************************************************************
Program Name: Creature tournament
Author:		  Robert Boespflug
Date:		  05/29/2017
Description:  This is the Medusa class function header file.
*******************************************************************/


#ifndef MEDUSA_HPP
#define MEDUSA_HPP

#include "Creature.hpp"

/*********************************************************************
Description: This is the Medusa class. This class represents the
Medusa creature in the creature fight program.
**********************************************************************/
class Medusa : public Creature
{
public:
	Medusa();

	virtual int attack() override;
	virtual int defense() override;

	const int MAX_SIDES = 6;
	const int MIN_SIDES = 1;
	const int GLARE_DEFENSE = -2;
};


#endif
