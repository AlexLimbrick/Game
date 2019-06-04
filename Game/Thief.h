#pragma once
#include <iostream>
#include <stdlib.h>
#include <string>
#include "Inventory.h"
#include "Potion.h"
#include "Player.h"

using namespace std;

class Thief:public Player
{
public:
	Thief();
	~Thief();
	virtual void Initialize();
	virtual int Attack();
	virtual void Special1();//dodge
	virtual int Special2();//Sneak attack

};

