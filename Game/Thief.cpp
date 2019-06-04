#include "Thief.h"



Thief::Thief()
{
}


Thief::~Thief()
{
}

void Thief::Initialize()
{
	cout << "Whats your name : ";
	cin >> name;
	health = 8;
	ac = 16;
	attack = 3;

	damage = rand() % 6 + 2;

	special1 = "Dodge";
	special2 = "Sneak Attack";
}

int Thief::Attack()
{
	ac = 16;
	roll = (rand() % 20 + 1) + attack;
	damage = rand() % 6 + 2;
	return roll;
}

void Thief::Special1()
{
	ac = 22;
}

int Thief::Special2()
{
	ac = 16;
	roll = (rand() % 20 + 1) + attack + 3;
	damage = (rand() % 6 + 2) + (rand() % 6 + 1) + (rand() % 6 + 1) ;
	return roll;
}
