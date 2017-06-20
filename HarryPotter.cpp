/************************************************************************
Program Name: Creature tournament
Author:		  Robert Boespflug
Date:		  05/29/2017
Description:  This is the HarryPotter class function implementation file.
*************************************************************************/

#include "HarryPotter.hpp"

//constructor
HarryPotter::HarryPotter()
{
	cout << endl;
	cout << "--> Harry Potter ready to fight! " << endl;
	cout << endl;
	strength_points = 10;
	armor_points = 0;
}

//destructor
HarryPotter::~HarryPotter() = default;


/***********************************************************
** Description: This is the attack function for the Harry
* Potter creature. Thi function overrides the base function
* in the creature class.
***********************************************************/
int HarryPotter::attack()
{
	cout << "Harry Potter attack!" << endl;
	int die_roll_1 = rand() % MAX_SIDES + MIN_SIDES;
	int die_roll_2 = rand() % MAX_SIDES + MIN_SIDES;
	int attackHarry = die_roll_2 + die_roll_1;
	return attackHarry;
}


/***********************************************************
** Description: This is the defense function for the Harry
* Potter creature. Thi function overrides the base function
* in the creature class.
***********************************************************/
int HarryPotter::defense()
{
	int die_roll_1 = rand() % MAX_SIDES + MIN_SIDES;
	int die_roll_2 = rand() % MAX_SIDES + MIN_SIDES;
	int defenseHarry = die_roll_2 + die_roll_1;
	return defenseHarry;
}
