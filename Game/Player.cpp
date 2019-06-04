#include "Player.h"



Player::Player(int _health, int _ac, int _attack, int _curInv, int _damage)
{
	health = _health;
	ac = _ac;
	attack = _attack;
	
	damage = _damage;
}

Player::Player(const Player & _copyPlayer)
{
	health = _copyPlayer.health;
	name = _copyPlayer.name;
	ac = _copyPlayer.ac;
	
	damage = _copyPlayer.damage;
	attack = _copyPlayer.attack;
	for(int i = 0; i <10 ;i++)
	{
		inventory[i] = _copyPlayer.inventory[i];
	}
	

	cout << "Player Copied!!" << endl;
}

Player & Player::operator=(const Player & _copyPlayer)
{
	health = _copyPlayer.health;
	name = _copyPlayer.name;
	ac = _copyPlayer.ac;
	
	damage = _copyPlayer.damage;
	attack = _copyPlayer.attack;

	for (int i =0; i <10; i++)
	{
		inventory[i] = _copyPlayer.inventory[i];
	}

	cout << "Player Assigned!!" << endl;
	
	return*this;
}


Player::~Player()
{
	
}

void Player::Initialize()
{
	
	cout << "Whats your name : ";
	cin >> name;
	
}

void Player::DisplayStats()
{
	cout << name <<"'s stats: " << endl;
	cout << "Health: " << health << endl;
	cout << "AC: " << ac << endl;
	cout << "Attack: " << attack << endl;
	cout << "Last Damage: " << damage << endl;
	system("pause");
	
}

void Player::AddToInv(string _item)
{
	inventory->AddToInv(_item);
	
}

bool Player::CheckInv(string _item)
{
	if (inventory->CheckInv(_item))
	{
		return true;
	}
	return false;
}

void Player::Specials()
{
	cout << "5. " << special1 << endl;
	cout << "6. " << special2 << endl;
}

int Player::Attack()
{
	roll = (rand() % 20 + 1) + attack;
	damage = rand() % 8 + 5;
	return roll;
}

void Player::Special1()
{
}

int Player::Special2()
{
	return 0;
}

void Player::Hit(int _damage)
{
	health = health - _damage;
	cout << "You've Been Hit!!!" << endl << "Health: " <<  health << endl;
}

void Player::UsePotion()
{
	health = health + potion.LightPotion();
	cout << "Health: " << health << endl;
}

void Player::DisplayInv()
{
	inventory->DisplayInv();
}

void Player::SetAC(int _AC)
{
	ac = ac +_AC;
}

void Player::SetHealth(int _Health)
{
	health = health + _Health;
}

void Player::SetAttack(int _Attack)
{
	attack = attack + _Attack;
}

void Player::SetDamage(int _Damage)
{
	damage = damage + _Damage;
}

bool Player::IsAlive()
{
	if (health < 1)
	{
		return false;
	}
	return true;
}


