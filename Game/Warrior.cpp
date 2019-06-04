#include "Warrior.h"



Warrior::Warrior()
{
}


Warrior::~Warrior()
{
}

void Warrior::Initialize()
{
	cout << "Whats your name : ";
	cin >> name;
	health = 12;
	ac = 16;
	attack = 5;

	damage = rand() % 8 + 5;
	
	special1 = "Block";
	special2 = "Power Attack";

}

int Warrior::Attack()
{
	ac = 16;
	roll = (rand() % 20 + 1) + attack;
	damage = rand() % 8 + 5;
	return roll;

}

void Warrior::Special1()// Block
{
	ac = 22;
}

int Warrior::Special2()
{
	damage = rand() % 12 + 5;
	ac = 16;
	roll = (rand() % 20 + 1) + attack;
	//damage = rand() % 8 + 5;
	return roll;
}
