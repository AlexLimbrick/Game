#include "Wizard.h"



Wizard::Wizard()
{
}


Wizard::~Wizard()
{
}

void Wizard::Initialize()
{
	cout << "Whats your name : ";
	cin >> name;
	health = 8;
	ac = 12;
	attack = 1;

	damage = rand() % 4 + 2;

	special1 = "Heal";
	special2 = "Fireball";
}

int Wizard::Attack()
{
	
	roll = (rand() % 20 + 1) + attack;
	damage = rand() % 4 + 2;
	return roll;
	
}

void Wizard::Special1()
{
	health = health + (rand() % 10 + 2);
}

int Wizard::Special2()
{
	roll = (rand() % 20 + 1) + 20;
	damage = rand() % 16 + 1;
	return roll;
	
}
