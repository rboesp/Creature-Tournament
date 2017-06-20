/*******************************************************************
Program Name: Creature tournament
Author:		  Robert Boespflug
Date:		  05/29/2017
Description:  This is the Medusa class function implementation file.
*******************************************************************/

#include "Medusa.hpp"

//Medusa constructor
Medusa::Medusa()
{
	cout << endl;
	cout << "--> Medusa ready to fight! " << endl;
	cout << endl;
	strength_points = 8;
	armor_points = 3;
}


/*********************************************************************
Description: This is the virtual attack function for a Medusa object.
This function returns the total of two six sided die rolls.
**********************************************************************/
int Medusa::attack()
{
	cout << "Medusa attack!" << endl;
	int die_roll_1 = rand() % MAX_SIDES + MIN_SIDES;
	int die_roll_2 = rand() % MAX_SIDES + MIN_SIDES;
	int attackMedusa = die_roll_2 + die_roll_1;
	if (attackMedusa == 12)
	{
		return -2;
	}
	else
	{
		return attackMedusa;
	}
}


/*********************************************************************
Description: This is the virtual defense function for a Medusa object.
This function returns the total of a six-sided die roll.
**********************************************************************/
int Medusa::defense()
{
	return rand() % MAX_SIDES + MIN_SIDES;
}

