#pragma once
#include <iostream>
#include <stdlib.h>
#include <string>
#include "Potion.h"

using namespace std;

class Enemy
{
public:
	Enemy(int _ac = 14, int _health = 10, int _damage = 2, int _attack = 2, int _potiontype = 1, string _name = "hi", bool _alive = true);
	Enemy(const Enemy& _copyEnemy);
	Enemy& operator=(const Enemy& _copyEnemy);
	~Enemy();

	int MyChoice();
	int Attack();
	void UsePotion();
	string GetName() { return name; }
	void Hit(int _damage);
	void Kill();

	int GetAC()const { return ac; }
	bool IsAlive() const { return alive; }
	int GetDam() const { return damage; }
protected:
	static int enemyCount;
	int health;
	int ac;
	int attack;
	int damage;
	int roll;
	bool alive ;
	int potionType;// 1 = light 2 = moderate
	string name;
	Potion potion;
};

