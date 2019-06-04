#pragma once
#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

class Potion
{
public:
	Potion();
	~Potion();
	int LightPotion();
	int ModeratePotion();
	
private:
	int heal;
};

