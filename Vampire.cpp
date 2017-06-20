#include "Creature.hpp"
#include "Vampire.hpp"

//constructor
Vampire::Vampire()
{
	cout << endl;
	cout << "--> VAMPIRE READY TO FIGHT! " << endl;
	cout << endl;
	strength_points = 18;
	armor_points = 1;
}

//vampire attack function
int Vampire::attack()
{
	cout << "Vampire attack!" << endl;
	int die_roll_attack;
	die_roll_attack = rand() % MAX_SIDES_ATTACK + MIN_SIDES_ATTACK;
	return die_roll_attack;
}

//vampire defense function
int Vampire::defense()
{
	int die_roll_defense;
	int charm_roll;
	die_roll_defense = rand() % MAX_SIDES_DEFENSE + MIN_SIDES_DEFENSE;
	charm_roll = rand() % 2 + 1;
	if (charm_roll == 1)
	{
		return -1;
	}
	else
	{
		return die_roll_defense;
	}
}

