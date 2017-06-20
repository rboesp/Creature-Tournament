/************************************************************************
Program Name: Creature tournament
Author:		  Robert Boespflug
Date:		  05/29/2017
Description:  This is the creatureMenu function header file.
*************************************************************************/

#pragma once


#include "Validation.hpp"

#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

//constants
const int MENU_CHOICE_HARRY = 1;
const int MENU_CHOICE_BARBARIAN = 2;
const int MENU_CHOICE_VAMPIRE = 3;
const int MENU_CHOICE_BLUEMEN = 4;
const int MENU_CHOICE_MEDUSA = 5;
const int MENU_CHOICE_EXIT = 6;

//menu function prototype
int creatureMenu();