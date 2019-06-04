#include "Enemy.h"


int Enemy::enemyCount = 0;
Enemy::Enemy(int _ac , int _health , int _damage ,int _attack, int _potiontype , string _name , bool _alive)
{
	ac = _ac;
	health = _health;
	damage = _damage;
	potionType = _potiontype;
	name = _name;
	alive = _alive;
	attack = _attack;
}

Enemy::Enemy(const Enemy & _copyEnemy)
{
	name = _copyEnemy.name;
	attack = _copyEnemy.attack;
	health = _copyEnemy.health;
	damage = _copyEnemy.damage;
	ac = _copyEnemy.ac;
	enemyCount++;
}

Enemy & Enemy::operator=(const Enemy & _copyEnemy)
{
	name = _copyEnemy.name;
	attack = _copyEnemy.attack;
	health = _copyEnemy.health;
	damage = _copyEnemy.damage;
	ac = _copyEnemy.ac;

	return*this;
}


Enemy::~Enemy()
{
}

int Enemy::Attack()
{
	roll = (rand() % 20 + 1) + attack;

	return roll;
}

void Enemy::UsePotion()
{
	if (potionType = 1)
	{ 
		health = health + potion.LightPotion();
	}
	if (potionType = 2)
	{
		health = health + potion.ModeratePotion();
	}
	
}



void Enemy::Hit(int _damage)
{
	cout << "You Hit The " << name << endl;
	health = health - _damage;
}

int Enemy::MyChoice()
{
	int myChoice = rand() % 100 + 1;
	if (health > 0)
	{
		if (myChoice < 90)
		{
			return 1;
		}
		else
		{
			return 2;
		}
	}
	else
	{
		return 0;
	}
	
}

void Enemy::Kill()
{
	alive = false;
}
