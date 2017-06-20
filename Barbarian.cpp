/************************************************************************
Program Name: Creature tournament
Author:		  Robert Boespflug
Date:		  05/29/2017
Description:  This is the Barbarian class function implementation file.
*************************************************************************/

#include "Barbarian.hpp"

//constructor
Barbarian::Barbarian()
{
	cout << endl;
	cout << "--> Barbarian ready to fight! " << endl;
	cout << endl;
	armor_points = 0;
	strength_points = 12;
}


//barbarian attack function
int Barbarian::attack()
{
	//return two 6-sides die rolls

	cout << "Barbarian attack!" << endl;
	cout << endl;

	//variables to hold die rolls 
	int die_roll_1;
	int die_roll_2;

	//roll both die
	die_roll_1 = rand() % MAX_SIDES + MIN_SIDES;
	die_roll_2 = rand() % MAX_SIDES + MIN_SIDES;

	//add both die rolls together to get attack number
	int attack_result;
	attack_result = die_roll_1 + die_roll_2;

	return attack_result;
}


//barbarian defense function
int Barbarian::defense()
{
	//return two 6-sides die rolls

	//variables to hold die rolls 
	int die_roll_1;
	int die_roll_2;

	//roll both die
	die_roll_1 = rand() % MAX_SIDES + MIN_SIDES;
	die_roll_2 = rand() % MAX_SIDES + MIN_SIDES;

	//add both die rolls together to get attack number
	int defense_result;
	defense_result = die_roll_1 + die_roll_2;

	return defense_result;
}

