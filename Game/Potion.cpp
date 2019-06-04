#include "Potion.h"



Potion::Potion()
{
}


Potion::~Potion()
{
}

int Potion::LightPotion()
{
	heal = rand() % 8 + 1;
	return heal;
}

int Potion::ModeratePotion()
{
	heal = ((rand() % 8 + 1)+ (rand() % 8 + 1));
	return heal;
}
