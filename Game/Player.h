#pragma once
#include <iostream>
#include <stdlib.h>
#include <string>
#include "Inventory.h"
#include "Potion.h"

using namespace std;

class Player
{
public:
	Player(int _health = 10, int _ac = 10, int _attack = 6, int _curInv = 0, int _damage = rand() % 8 + 5);
	Player(const Player& _copyPlayer);
	Player& operator=(const Player& _copyPlayer);
	~Player();
	virtual void Initialize();
	void DisplayStats();
	void AddToInv(string _item);
	bool CheckInv(string _item);
	void Specials();
	virtual int Attack();
	int GetAC() const { return ac; }
	int GetDam() const { return damage; }
	virtual void Special1();
	virtual int Special2();
	void Hit(int _damage);
	void UsePotion();
	void DisplayInv();
	void SetAC(int _AC);
	void SetHealth(int _Health);
	void SetAttack(int _Attack);
	void SetDamage(int _Damage);
	bool IsAlive();
protected:
	int health;
	int ac;
	int attack;
	int damage;
	int roll;
	string name;
	string special1;
	string special2;
	Inventory* inventory = new Inventory();
	
	
	Potion potion;
};

