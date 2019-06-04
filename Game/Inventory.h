#pragma once

#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

class Inventory
{
public:
	Inventory();
	~Inventory();
	void DisplayInv();
	void AddToInv(string _item);
	bool CheckInv(string _item);
private:
	string inventory[10];
	int curInv;
};

