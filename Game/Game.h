#pragma once
// My headers
#include "Player.h"
#include "Goblin.h"
#include "Warrior.h"
#include "Wizard.h"
#include "Thief.h"
#include "Map.h"

// Windows stuff
#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

class Game
{
public:
	Game();
	~Game();
	void Initialize();
	void RunGame();
	
private:
	
	Player* player = new Player();
	Enemy* enemy = new Enemy();
	Map* map = new Map();
	bool running;
	int choice;
	void MapMenu();
	void EncounterMenu();
	void EnemyTurn();
	void Input();
	void Area();
	void Encounter();
	void EncounterInput();
	int x;
	int y;
	bool encounter;
	void Win();
	void Dead();

};

