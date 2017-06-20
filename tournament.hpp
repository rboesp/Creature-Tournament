#pragma once

/**************************************************************
* Description: This is the tournament class. This class represents
the tournament being run. It has three queues, two lineups and a
winner pile.
***************************************************************/

#include "Queue.hpp"
#include "QueueNode.hpp"


class Tournament
{
private:
	const int LINEUP_SIZE = 10;
	Queue lineup1;
	Queue lineup2;
	Queue loserPile;
	QueueNode * frontLineup1;
	QueueNode * frontLineup2;
	Creature * user_defined_creature;
	Creature * roundWinner;
	string assignCreatureName();
	int size_lineup1 = LINEUP_SIZE;
	int size_lineup2 = LINEUP_SIZE;
	int loser_size = 0;

public:
	Tournament();
	~Tournament();
	void fillTwoLineups();
	void fillLineup(Queue *q, int lineup);
	int tournament_creatureFight();
	void printLoserPile();
	void printWinnerPile();
	void removeCreatures(Queue * q, int size);
};
