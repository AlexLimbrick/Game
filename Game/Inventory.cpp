#include "Inventory.h"



Inventory::Inventory()
{
	for (int i = 0; i < 10; i++)
	{
		inventory[i] = "<EMPTY>";
	}
	curInv = 0;
}


Inventory::~Inventory()
{
}

void Inventory::DisplayInv() // loops through the inventory printing its contents on the screen
{
	for (int i = 0; i < 10; i++)
	{
		int slot = i + 1;
		cout << "Slot" << slot << ": " << inventory[i] << endl;

	}
	system("pause");
}

void Inventory::AddToInv(string _item)
{
	if (curInv < 10)// adds an item to the inventory in the next free position
	{
		inventory[curInv] = _item;
		curInv++;
	}
	else
	{
		cout << "INVENTORY FULL" << endl;
	}
}

bool Inventory::CheckInv(string _item)// loops through the inventory to check if a specific item is contianed in the inventory
{
	for (int i = 0; i < 10; i++)
	{
		if (inventory[i] == _item)
		{
			return true;
		}
		
	}
	return false;
}
