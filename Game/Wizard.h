#pragma once
#include <iostream>
#include <stdlib.h>
#include <string>
#include "Inventory.h"
#include "Potion.h"
#include "Player.h"

using namespace std;

class Wizard:public Player
{
public:
	Wizard();
	~Wizard();
	virtual void Initialize();
	virtual int Attack();
	virtual void Special1();//heal
	virtual int Special2();//Fireball

};

