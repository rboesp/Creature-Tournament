/************************************************************************
Program Name: Creature tournament
Author:		  Robert Boespflug
Date:		  05/29/2017
Description:  This is the BlueMen class function implementation file.
*************************************************************************/

#include "BlueMen.hpp"

//Blue Men constructor
BlueMen::BlueMen()
{
	cout << endl;
	cout << "--> Blue men ready to fight! " << endl;
	cout << endl;
	strength_points = 12;
	armor_points = 3;
}


/*********************************************************************
Description: This is the virtual attack function for a Blue Men object.
This function returns the total of two ten-sided die rolls.
**********************************************************************/
int BlueMen::attack()
{
	cout << "Blue men attack!" << endl;
	int attack_roll_1 = rand() % MAX_SIDES_ATTACK + MIN_SIDES_ATTACK;
	int attack_roll_2 = rand() % MAX_SIDES_ATTACK + MIN_SIDES_ATTACK;
	int finalAttack = attack_roll_1 + attack_roll_2;
	return finalAttack;
}


/*********************************************************************
Description: This is the virtual defense function for a Blue Men object.
This function returns the total of either three six sides die rolls,
two six sided die rolls, or one six sided die roll depending on the
strength points of the Blue Men object fighting.
**********************************************************************/
int BlueMen::defense()
{
	if (strength_points >= 8)
	{
		int defense_roll_1 = rand() % MAX_SIDES_DEFENSE + MIN_SIDES_DEFENSE;
		int defense_roll_2 = rand() % MAX_SIDES_DEFENSE + MIN_SIDES_DEFENSE;
		int defense_roll_3 = rand() % MAX_SIDES_DEFENSE + MIN_SIDES_DEFENSE;
		int final_defense_roll = defense_roll_1 + defense_roll_2 + defense_roll_3;
		return final_defense_roll;
	}
	else if (strength_points >= 4)
	{
		cout << endl;
		cout << "-------> The blue men lost some defense!!" << endl;
		int defense_roll_1 = rand() % MAX_SIDES_DEFENSE + MIN_SIDES_DEFENSE;
		int defense_roll_2 = rand() % MAX_SIDES_DEFENSE + MIN_SIDES_DEFENSE;
		int final_defense_roll = defense_roll_1 + defense_roll_2;
		return final_defense_roll;
	}
	else /*if (strength_points < 4)*/
	{
		cout << endl;
		cout << "-------> The blue men lost more defense!! Very vulnerable!" << endl;
		int defense_roll_1 = rand() % MAX_SIDES_DEFENSE + MIN_SIDES_DEFENSE;
		int final_defense_roll = defense_roll_1;
		return final_defense_roll;
	}
}
