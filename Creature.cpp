/************************************************************************
Program Name: Creature tournament
Author:		  Robert Boespflug
Date:		  05/29/2017
Description:  This is the Creature class function implementation file.
*************************************************************************/

#include "Creature.hpp"
#include "HarryPotter.hpp"

//constructor
Creature::Creature()
{ 
	strength_points = 0;
	armor_points = 0;
}


//destructor
Creature::~Creature() = default;



/********************************************************
** Description: This is the creatureFight function. This 
* represents two creatures fighting each other. This 
* function accepts two creature ptr's and returns a   
* creature ptr that represents the creature that won the 
* fight.
********************************************************/
Creature* Creature::creatureFight(Creature * creature1, Creature * creature2) 
{
	cout << "\t" << "***CREATURE FIGHT!***" << endl;
	cout << endl;

	//roll two sided die to get random first player
	int firstAttacker = rand() % 2 + 1;

	//print firstAttacker to screen
	cout << "First attacker: " << firstAttacker << endl;

	if (firstAttacker == 1)
	{
		cout << "---> First Attacker: Creature 1" << endl;
	}
	else if (firstAttacker == 2)
	{
		cout << "---> First Attacker: Creature 2" << endl;
	}
	cout << endl;

	int roundCount1 = 0;
	int roundCount2 = 0;

	//while the creatures are alive, fight
	while (creature1->strength_points > 0 && creature2->strength_points > 0)
	{
		cout << "  **Creature 1 strength: " << creature1->strength_points << endl;
		cout << "  **Creature 2 strength: " << creature2->strength_points << endl;
		cout << endl;
		cout << endl;

		if (firstAttacker == 1) //creature1 = first player
		{
			roundCount1++;
			//creature 1 attack
			cout << "Creature 1 --> ";  //print inside all the creature attack functions
			int creature1Attack = creature1->attack();
			int creature2Defense = creature2->defense();
			int creature2Damage_before_armor = 0;
			int creature2Damage_after_armor = 0;

			//check special powers
			if (creature2Defense == -1) //charm
			{
				cout << endl;
				cout << "----> Vampire CHARM was used!" << endl;
				cout << endl;
			}
			else if (creature2Defense == -2) //glare
			{
				cout << endl;
				cout << "----> Medusa GLARE was used!" << endl;
				cout << endl;
			}
			else
			{
				//no charm or glare used
				creature2Damage_before_armor = creature1Attack - creature2Defense;
				creature2Damage_after_armor = creature2Damage_before_armor - creature2->armor_points;
			}

			//if damage not negative
			if (creature2Damage_after_armor >= 0)
			{
				creature2->strength_points -= creature2Damage_after_armor;
			}
			else
			{
				creature2Damage_after_armor = 0;
			}

			//print info
			cout << endl;
			cout << "\t" << "ATTACK SUMMARY - Round: " << roundCount1 << endl;
			cout << "\t" << "  Creature 1 attack: " << creature1Attack << endl;
			cout << "\t" << "  Creature 2 defense: " << creature2Defense << endl;
			cout << "\t" << "  Damage: " << creature2Damage_before_armor << endl;
			cout << "\t" << "  Creature 2 armor points: " << creature2->armor_points << endl;
			cout << "\t" << "  Creature 2 damage taken: " << creature2Damage_after_armor<< endl;
			cout << endl;
			firstAttacker++;
		}
		else
		{
			roundCount2++; 
			//creature 2 attack
			cout << "Creature 2 --> ";
			int creature2Attack = creature2->attack();
			int creature1Defense = creature1->defense();
			int creature1Damage_before_armor = 0;
			int creature1Damage_after_armor = 0;

			if (creature1Defense == -1) //charm
			{
				cout << endl;
				cout << "----> Vampire charm was used!" << endl;
				cout << endl;
			}
			else if (creature1Defense == -2) //glare
			{
				cout << endl;
				cout << "----> Medusa GLARE was used!" << endl;
				cout << endl;
			}
			//no charm or glare used
			else
			{
				creature1Damage_before_armor = creature2Attack - creature1Defense;
				creature1Damage_after_armor = creature1Damage_before_armor - creature1->armor_points;
			}

			//if damage not negative
			if (creature1Damage_after_armor >= 0)
			{
				creature1->strength_points -= creature1Damage_after_armor;
			}
			else
			{
				creature1Damage_after_armor = 0;
			}

			//print info
			cout << endl;
			cout << "\t" << "ATTACK SUMMARY - Round: " << roundCount2 << endl;
			cout << "\t" << "  Creature 2 attack: " << creature2Attack << endl;
			cout << "\t" << "  Creature 1 defense: " << creature1Defense << endl;
			cout << "\t" << "  Damage: " << creature1Damage_before_armor << endl;
			cout << "\t" << "  Creature 1 armor points: " << creature1->armor_points << endl;
			cout << "\t" << "  Creature 1 damage taken: " << creature1Damage_after_armor << endl;
			cout << "\t" << endl;
			firstAttacker--;
		}

		//if a creature1 dead, check if harry
		if (creature1->strength_points <= 0)
		{
			//cast to harry, if harry and first life, bring back to life
			HarryPotter *harryPotterPtr	 = dynamic_cast<HarryPotter *>(creature1);
			if (harryPotterPtr)
			{
				//creature1 is of type 'Harry Potter'
				if (harryPotterPtr->firstLife == true) //if first time through
				{
					//bring (creature1) harry back to life
					creature1->strength_points = harryPotterPtr->SECOND_LIFE_STRENGTH;					
					cout << "Creature 1 ---> Harry magically comes back to life!!" << endl;
					cout << endl;
					harryPotterPtr->firstLife = false;
				}
			}

		}
		//if creature2 dead, check if harry
		else if (creature2->strength_points <= 0)
		{
			//cast to harry, if harry and first time, bring back to life
			HarryPotter *harryPotterPtr = dynamic_cast<HarryPotter *>(creature2);
			if (harryPotterPtr)
			{
				//creature2 is of type 'Harry Potter'
				if (harryPotterPtr->firstLife == true) //if first time through
				{
					//bring (creature2) harry back to life
					creature2->strength_points = harryPotterPtr->SECOND_LIFE_STRENGTH;
					cout << "Creature 2 ---> Harry magically comes back to life!!" << endl;
					cout << endl;
					harryPotterPtr->firstLife = false;
				}
			}
		}
	} 


	//if here, somebody lost, display winner and final strength scores
	if (creature1->strength_points <= 0)
	{
		cout << endl;
		cout << "**Creature 2 wins!**" << endl;
		cout << "--> Creature 1 strength: " << creature1->strength_points << endl;
		cout << "--> Creature 2 strength: " << creature2->strength_points << endl;
		cout << endl;
		return creature2;
	}
	else
	{
		cout << endl;
		cout << "**Creature 1 wins!**" << endl;
		cout << "--> Creature 1 strength: " << creature1->strength_points << endl;
		cout << "--> Creature 2 strength: " << creature2->strength_points << endl;
		cout << endl;
		return creature1;
	}
}



/********************************************************
** Description: This is the recoverHealth function. This 
* void function accepts no arguments and recovers 50%
* of the winning creatures health before they get put to
* the back of their lineup.
********************************************************/
void Creature::recoverHealth()
{
	//cout << "FOR TESTING before-----------------> : " << strength_points << endl;
	double half = strength_points / 2;//could do quarter?
	int noDecimalHalf = floor(half);
	strength_points += noDecimalHalf;
	//cout << "FOR TESTING after-----------------> : " << strength_points << endl;
}

