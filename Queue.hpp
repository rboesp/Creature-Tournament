/*******************************************************************
Program Name: Creature tournament
Author:		  Robert Boespflug
Date:		  05/29/2017
Description:  This is the Queue class function header file.
*******************************************************************/


#ifndef QUEUE_HPP
#define QUEUE_HPP

#include "QueueNode.hpp"
#include "Creature.hpp"
#include <iostream>
#include <string>
using std::string;


/********************************************************
** Description: This is the Queue class. This class 
* represents a queue doubly circular linked list with a 
* ptr to the front of the list and the back of the list.
********************************************************/
class Queue
{

public:
	//class member variables
	QueueNode * front;
	QueueNode * back;

	//class member functions
	void addBack(string name, Creature * creatureType);
	QueueNode * getFront();
	void removeFront();
	bool isEmpty();
	void printQueue();

	//constructor/destructor
	Queue();
	~Queue();
};



#endif
