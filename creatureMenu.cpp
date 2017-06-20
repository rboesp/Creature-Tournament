/************************************************************************
Program Name: Creature tournament
Author:		  Robert Boespflug
Date:		  05/29/2017
Description:  This is the creatureMenu function implementation file.
*************************************************************************/

#include "creatureMenu.hpp"


/********************************************************
*Description: This is the creatureMenu function. This 
* function accepts no arguments and returns an integer
* that represents the option the user picked in the menu.
********************************************************/
int creatureMenu()
{
	int choice; //holds user choice
	cout << "\t\nPICK A CREATURE TO PUT INTO LINEUP! \n";

	cout << "\t\t" << MENU_CHOICE_HARRY << ") HARRY POTTER \n";
	cout << "\t\t" << MENU_CHOICE_BARBARIAN << ") BARBARIAN \n";
	cout << "\t\t" << MENU_CHOICE_VAMPIRE << ") VAMPIRE \n";
	cout << "\t\t" << MENU_CHOICE_BLUEMEN << ") BLUE MEN \n";
	cout << "\t\t" << MENU_CHOICE_MEDUSA << ") MEDUSA \n";
	cout << "\t\t" << MENU_CHOICE_EXIT << ") EXIT \n\n";

	cout << "CHOICE (1-5): ";
	cout << "---> ";
	is_int(&choice); //validates user choice or integer

	bool not_exit = true;
	while (not_exit)
	{
		if (choice == MENU_CHOICE_HARRY)
		{
			cout << endl;
			cout << "\t*You picked Harry Potter!!*" << endl; //may want to delete these because of doubles//
			not_exit = false;
			cout << endl;
		}
		else if (choice == MENU_CHOICE_BARBARIAN)
		{
			cout << endl;
			cout << "\t*You picked the barbarian!!*" << endl;
			not_exit = false;
			cout << endl;
		}
		else if (choice == MENU_CHOICE_VAMPIRE)
		{
			cout << endl;
			cout << "\t*You picked to be a vampire!!*" << endl;
			not_exit = false;
			cout << endl;
		}
		else if (choice == MENU_CHOICE_BLUEMEN)
		{
			cout << endl;
			cout << "\t*You picked the Blue Men!!*" << endl;
			not_exit = false;
			cout << endl;
		}
		else if (choice == MENU_CHOICE_MEDUSA)
		{
			cout << endl;
			cout << "\t*You picked to be Medusa!!*" << endl;
			not_exit = false;
			cout << endl;
		}
		else if (choice == MENU_CHOICE_EXIT) //exit program
		{
			cout << "---> Thank you for playing!" << endl;
			cout << endl;
			exit(0);
		}
		else //validates for a menu option
		{
			cout << endl;
			cout << "\t---> ERROR: You must pick a menu option!" << endl;
			cout << endl;
			choice = creatureMenu();
		}
	}
	return choice;
}