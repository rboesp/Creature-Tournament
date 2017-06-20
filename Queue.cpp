/*******************************************************************
Program Name: Creature tournament
Author:		  Robert Boespflug
Date:		  05/29/2017
Description:  This is the Queue class function implementation file.
*******************************************************************/


#include "Queue.hpp"
#include "QueueNode.hpp"


//default constructor
Queue::Queue()
{
	front = nullptr;
	back = nullptr;
}



/********************************************************
*Description: This is the addBack() function. This void
function accepts an integer argument and adds a newly
created node to the back of the Queue.
********************************************************/
void Queue::addBack(string nodeName, Creature * creatureType)
{
	QueueNode * newNodePtr  = back;

	//if empty
	if (newNodePtr == nullptr)
	{
		//make new node
		newNodePtr = new QueueNode(nodeName, creatureType);

		//make front and back point to new node
		front= newNodePtr;
		back = newNodePtr;

		//make circular
		newNodePtr->prev = back;
		newNodePtr->next = front;
	}
	else
	{
		//make next of back node a new node
		newNodePtr->next = new QueueNode(nodeName, creatureType);

		//make new node point back to old back node
		newNodePtr->next->prev = newNodePtr;

		//make circular by making back node next point to front node
		newNodePtr->next->next = front;

		//make back point to new back node
		back = newNodePtr->next;
	}
}



/********************************************************
*Description: This is the getFront() function. This 
function accepts no arguments and returns the front 
node name of the Queue, which is an integer.
********************************************************/
QueueNode * Queue::getFront() 
{
	return front;
}



/********************************************************
*Description: This is the removeFront() function. This 
void function accepts no arguments and removes the first
node of the Queue.
********************************************************/
void Queue::removeFront()
{
	if (front != nullptr)
	{
		QueueNode * nodePtr = front;
	
		//one item in list
		if (front == back)
		{
			front = nullptr;
			back = nullptr;
		}
	
		//two or more items in list
		else
		{
			nodePtr->next->prev = back;
			front = nodePtr->next;
		}

		//delete memory
		/*delete nodePtr->creatureType;
		nodePtr->creatureType = nullptr;*/
		nodePtr->creatureType = nullptr;
		delete nodePtr;
		nodePtr = nullptr; 
	}
}



/********************************************************
*Description: This is the isEmpty() function. This function
returns a bool that tells if the Queue has any nodes in it
or if it is an empty queue with no nodes. 
********************************************************/
bool Queue::isEmpty()
{
	if (front == nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}



/********************************************************
*Description: This is the printQueue() function. This 
void function prints the contents of the Queue.
********************************************************/
void Queue::printQueue()
{
	QueueNode * newNode = front;

	cout << newNode->name << " ";
	newNode = newNode->next;

	while (newNode != back->next)
	{
		cout << newNode->name << " ";
		newNode = newNode->next;
	}
	cout << endl;
}


//destructor
 Queue::~Queue()
 {
	 //while there is still a node in Queue
	 while (front != nullptr)
	 {
		 //remove the first node of the Queue
		 removeFront();
	 }
 }
