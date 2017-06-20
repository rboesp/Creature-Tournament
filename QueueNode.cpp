/*******************************************************************
Program Name: Creature tournament
Author:		  Robert Boespflug
Date:		  05/29/2017
Description:  This is the QueueNode struct implementation file.
*******************************************************************/


#include "QueueNode.hpp"

//struct constructor - initializes new nodes
QueueNode::QueueNode(string nodeName, Creature * creature_Type)
{
	name = nodeName;
	creatureType = creature_Type;
	next = nullptr;
	prev = nullptr;
}
