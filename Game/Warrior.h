#pragma once
#include <iostream>
#include <stdlib.h>
#include <string>
#include "Inventory.h"
#include "Potion.h"
#include "Player.h"

using namespace std;

class Warrior:public Player
{
public:
	Warrior();
	~Warrior();
	virtual void Initialize();
	virtual int Attack();
	virtual void Special1();//Block
	virtual int Special2();//Power Attack

};

