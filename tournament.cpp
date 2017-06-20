#include "tournament.hpp"
#include "Creature.hpp"
#include "Barbarian.hpp"
#include "Vampire.hpp"
#include "HarryPotter.hpp"
#include "BlueMen.hpp"
#include "Medusa.hpp"
#include "creatureMenu.hpp"


//default constructor
Tournament::Tournament()
{
	user_defined_creature = nullptr;
	roundWinner = nullptr;
}


//destructor
Tournament::~Tournament()
{
	removeCreatures(&loserPile, loser_size);
	lineup1.~Queue();
	lineup2.~Queue();
	loserPile.~Queue();
}



/********************************************************
*Description: This is the fillTwoLineups function. This 
void function accepts no arguments and calls the fillLineups
function twice too fill up two lineups.
********************************************************/
void Tournament::fillTwoLineups()
{
	cout << "\n-----------> ***FILL FIRST LINEUP!: " << endl;
	fillLineup(&lineup1, 1);

	cout << "\n\n-----------> ***FILL SECOND LINEUP!: " << endl;
	fillLineup(&lineup2, 2);

}



/********************************************************
*Description: This is the fillLineup function. This void function
accepts a pointer to a Queue which represents a lineup and and integer 
 that represents which lineup is being filled as arguments. This 
function fills up the lineups used in the tournament. 
********************************************************/
void Tournament::fillLineup(Queue * q, int lineup)
{
	int count = 0;
	int choice;
	string name;
	
	while (count < LINEUP_SIZE)
	{
		cout << "\n\tLineup size: " << LINEUP_SIZE << endl;
		cout << "\tCreatures entered: " << count << endl;
		cout << endl;
		choice = creatureMenu();

		//assign creature1 to a type of creature
		if (choice == MENU_CHOICE_BARBARIAN)
		{
			//create creature
			user_defined_creature = new Barbarian;
			 
			////have user set name
			name = assignCreatureName();
			
			//assign creature to node
			q->addBack(name, user_defined_creature);

			cout << "\nLINEUP: ";
			q->printQueue();	
		}
		else if (choice == MENU_CHOICE_VAMPIRE)
		{
			//create creature
			user_defined_creature = new Vampire;
			
			////have user set the name
			name = assignCreatureName();
			
			//assign creature to node
			q->addBack(name, user_defined_creature);
			
			cout << "\nLINEUP: ";
			q->printQueue();
		}
		else if (choice == MENU_CHOICE_HARRY)
		{
			//create creature
			user_defined_creature = new HarryPotter;
			
			//have user set the name
			name = assignCreatureName();
			
			//assign creature to node
			q->addBack(name, user_defined_creature);

			cout << "\nLINEUP: ";
			q->printQueue();
		}
		else if (choice == MENU_CHOICE_BLUEMEN)
		{
			//create creature
			user_defined_creature = new BlueMen;

			////have user set the name
			name = assignCreatureName();

			//assign creature to node
			q->addBack(name, user_defined_creature);

			cout << "\nLINEUP: ";
			q->printQueue();
		}
		else if (choice == MENU_CHOICE_MEDUSA)
		{
			//create creature
			user_defined_creature = new Medusa;

			////have user set the name
			name = assignCreatureName();

			//assign creature to node
			q->addBack(name, user_defined_creature);

			cout << "\nLINEUP: ";
			q->printQueue();
		}
		count++;
	}
	cout << "\n---> LINEUP " << lineup << ": ";
	q->printQueue();
}



/********************************************************
*Description: This is the tournament_creatureFight function.
This function represents the heads of two lineups fighting 
against each other. The winner will go to the back of the
lineup, and the loser goes to the shared loser pile.
The function accepts no arguments and returns an integers  
representing which of the two lineups won the tournament. 
********************************************************/
int Tournament::tournament_creatureFight() 
{
	//while neither lineup is empty
	while (lineup1.front != nullptr && lineup2.front != nullptr)
	{
		//have 'heads' of lineups fight each other
		frontLineup1 = lineup1.front;
		frontLineup2 = lineup2.front;

		//'winner' captures round winner
		roundWinner = roundWinner->creatureFight(frontLineup1->creatureType, frontLineup2->creatureType);

		if (roundWinner == frontLineup1->creatureType)
		{
			//print round winner name to screen
			cout << "\n---> Lineup1: " << frontLineup1->name << " WON!\n" << endl;

			//recover health
			frontLineup1->creatureType->recoverHealth();

			//put winner to back of lineup...
			lineup1.addBack(frontLineup1->name, frontLineup1->creatureType);

			//...and remove winner from front of lineup
			lineup1.removeFront();

			//next, put loser in loser pile 
			loserPile.addBack(frontLineup2->name, frontLineup2->creatureType);

			//and remove loser from lineup completely
			lineup2.removeFront();

			size_lineup2--;
			loser_size++;
		}
		else if (roundWinner == frontLineup2->creatureType)
		{
			//print round winner name to screen
			cout << "\n---> Lineup2: " << frontLineup2->name << " WON!\n" << endl;

			//recover health
			frontLineup2->creatureType->recoverHealth();

			//add winner to the back...
			lineup2.addBack(frontLineup2->name, frontLineup2->creatureType);

			//...and remove winner from front of lineup1
			lineup2.removeFront();

			//next, put loser in loser pile... 
			loserPile.addBack(frontLineup1->name, frontLineup1->creatureType);

			//...and remove loser from lineup completely
			lineup1.removeFront();

			size_lineup1--;
			loser_size++;
		}
	}

	//if first lineup is empty
	if (lineup1.front == nullptr)
	{
		removeCreatures(&lineup2, size_lineup2);
		//return second lineup as the tournament winner
		return 2;
	}
	//if second lineup is empty
	else if (lineup2.front == nullptr)
	{
		removeCreatures(&lineup1, size_lineup1);
		//return first lineup as the tournament winner
		return 1;
	}
	else
	{
		//error
		return 0;
	}
}



/********************************************************
*Description: This is the printLoserPile function. This 
void function accepts no arguments and prints the contents
of the loser pile.
********************************************************/
void Tournament::printLoserPile()
{
	QueueNode * frontNode = loserPile.front;

	cout << "\nHERE IS THE LOSER PILE: ";
	cout << frontNode->name << " ";
	frontNode = frontNode->next;

	//while front not equal to front (because circular)
	while (frontNode != loserPile.back->next)
	{
		cout << frontNode->name << " ";
		frontNode = frontNode->next;
	}
	cout << endl;
}



/********************************************************
*Description: This is the printWinnerPile function. This
void function accpets no arguments and prints the contents
of the winning lineup. 
********************************************************/
void Tournament::printWinnerPile()
{
	cout << "\nWINNERS: ";

	//lineup2 winner
	if (lineup1.front == nullptr && lineup2.front != nullptr)
	{
		lineup2.printQueue();
		//removeCreatures(&lineup2, size_lineup2);
	}
	//lineup1 winner
	else if (lineup1.front != nullptr && lineup2.front == nullptr)
	{
		lineup1.printQueue();
		//removeCreatures(&lineup1, size_lineup1);
	}
}


/********************************************************
*Description: This is the removeCreatures function. This
void function accepts a pt to a queue and the sie that 
represents the number of elements in the queue. This 
function de-allocates the memory associates with the nodes
creatureType ptr.
********************************************************/
void Tournament::removeCreatures(Queue * q, int size) 
{

	QueueNode * deleteNode = q->front;
	for (int x = 0; x < size; x++)
	{
		delete deleteNode->creatureType;
		deleteNode->creatureType = nullptr;
		deleteNode = deleteNode->next;
	}
}



/********************************************************
*Description: This is the assignCreatureName function. 
This function accepts no arguments and retrns a string
that represents the name the user gave to the creature
they recently picked from the creatureMenu.
********************************************************/
string Tournament::assignCreatureName()
{
	string name;
	cout << "\nEnter a name for the creature: " << endl;
	cout << "---> ";
	cin.ignore();
	std::getline(cin, name);
	return name;
}
