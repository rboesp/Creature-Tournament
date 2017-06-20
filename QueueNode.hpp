/*******************************************************************
Program Name: Creature tournament
Author:		  Robert Boespflug
Date:		  05/29/2017
Description:  This is the QueueNode struct header file.
*******************************************************************/



/********************************************************
** Description: This is the QueueNode struct. This struct 
* reprents a node in a queue linked list. The node has 
* a next ptr that points to the next node in the liast, a
* prev ptr that points to the last ptr in the list, a string
* that represnts the name of a creature, and a ptr to a 
* creature that represents the type of creature held in the 
* node.
********************************************************/

#pragma once

#include "Creature.hpp"

//struct makes new queue nodes 
//to be put into the queue
struct QueueNode
{
	string name;
	Creature * creatureType;
	QueueNode * next;
	QueueNode * prev;
	QueueNode(string name, Creature * creature_Type);
};
