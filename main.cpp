/*****************************************************************************
** Program Name: Creature Tournament
** Author:		 Robert Boespflug
** Date:		 05/29/2017
** Description:	 This program is a simulation for a tournament with creatures.
* The creatures are stored in a queue linked-list, with the heads of each queue
* lineup fighting each other. The winner will go the the back of the queue, the 
* loser will go to the back of the loser pile (queue). 
******************************************************************************/


#include "Creature.hpp"
#include "tournament.hpp"
#include "Validation.hpp"
#include <time.h>
#include <cstdlib>

int main()
{
	//set random number gen. seed
	srand(time(nullptr));
	
	int playAgain;
	int winner;
	
	while (true)
	{
		cout << "\nWelcome!!\n" << endl;
		
		//make a tournament object
		Tournament creatureTournament;
		
		//have user fill up two lineups to play tournament
		creatureTournament.fillTwoLineups();
		
		cout << "\nTOURNAMENT READY!!!\n" << endl;

		//have user play tournament
		winner = creatureTournament.tournament_creatureFight();

		//print winner to screen
		if (winner == 1)
		{
			cout << "***************************************************************" << endl;
			cout << "\nWINNING LINEUP: LINEUP1" << endl;
			creatureTournament.printWinnerPile();
		}
		else if (winner == 2)
		{
			cout << "**************************************************************" << endl;
			cout << "\nWINNING LINEUP: LINEUP2" << endl;
			creatureTournament.printWinnerPile();
		}
		else
		{
			cout << "Error!" << endl;
		}

		//i think you want to run it every time here

		creatureTournament.printLoserPile();

		//ask user to go again
		cout << "\nWould you like to play again?: Enter 1 for yes and 0 for no!\n" << endl;
		cout << "---> ";
		
		is_int(&playAgain);
		while (playAgain != 1 && playAgain != 0)
		{
			cout << "\n----> Please enter a 1 or a 0!!! \n" << endl;
			is_int(&playAgain);
		}
		
		if (playAgain == 0)
		{
			cout << "\nThank you for playing!\n" << endl;
			creatureTournament.~Tournament();										//runs Queue destructors and frees memory
			exit(0);
		}
	}
}
