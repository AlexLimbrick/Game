#include "Game.h"
#include <random>
#include <time.h>



Game::Game()
{
	srand(time(NULL));
	x = 0;
	y = 0;
	encounter = false;
}




void Game::Initialize()
{
	cout << "Choose Your Class " << endl;
	cout << "1. Warrior " << endl;
	cout << "2. Wizard" << endl;
	cout << "3. Thief" << endl;
	cin >> choice;
	system("cls");
	if (choice ==1)
	{
		player = new Warrior();
		
	}
		
		
	if (choice == 2)
	{
		player = new Wizard();
		
	}
		
	if (choice == 3)
	{
		player = new Thief();
		
	}
		

	
	running = true;
	player->Initialize();
	system("cls");
	
	
}

void Game::RunGame()
{
	

	

	 
	
	while (running)
	{
		
			MapMenu();
		
		
		// Where the players choice is processed
		Input();
		// Enemys Turn
		if (running && encounter == true)
		{
			Encounter();
			
			
		}
		if (player->CheckInv("Key") == true)
		{
			
		}
		

	}
}



void Game::MapMenu()// the normal menu
{
	system("cls");
	map->update(x,y);
	map->drawMap();
	Area();
	cout << "---------------------------" << endl;
	cout << "1. Display Your Stats" << endl;
	cout << "2. Display Your Inventory" << endl;
	cout << "3. Move North" << endl;
	cout << "4. Move South" << endl;
	cout << "5. Move East" << endl;
	cout << "6. Move West" << endl;
	cout << "7. Fight enemy" << endl;
	cout << "0. EXIT GAME" << endl;
	cout << "---------------------------" << endl;
	cout << endl<< "Choose what you want to do" << endl;
	cout << "---------------------------" << endl;
	cin >> choice;
}

void Game::EncounterMenu()// the menu made for encounters
{
	system("cls");
	cout << "---------------------------" << endl;
	cout << "1. Display Your Stats" << endl;
	cout << "2. Display Your Inventory" << endl;
	cout << "3. Attack" << endl;
	cout << "4. Use Potion" << endl;
	player->Specials(); // 5 and 6
	cout << "0. EXIT GAME" << endl;
	cout << "---------------------------" << endl;
	cout << endl << "Choose what you want to do" << endl;
	cout << "---------------------------" << endl;
	cin >> choice;
}

void Game::EnemyTurn()// does the enemies turn 
{
	system("pause");
	system("cls");
	cout << "---------------------------" << endl;
	cout << "Enemys Turn" << endl;
	cout << "---------------------------" << endl<<endl;
	switch (enemy->MyChoice())
	{
	case 1:
		cout << "The "<< enemy->GetName() << " Attacks"<<endl;
		system("pause");
		if (enemy->Attack() >= player->GetAC())
		{
			player->Hit(enemy->GetDam());
		}
		else
		{
			cout << "You Were Missed" << endl;
		}
		
		break;
	case 2:
		enemy->UsePotion();
		cout << "Enemy Used A Potion" << endl;
		
		break;
	case 0:
		cout << "The " << enemy->GetName() << " is Dead" << endl;
		
		enemy->Kill();
		break;
	}
	system("pause");
	
}
void Game::Input()// gets input from the map menu
{
	switch (choice)
	{
	case 1:
		player->DisplayStats();
		break;
	case 2:
		player->DisplayInv();
		break;
	case 3://north
		if (y > 1)
		{
			y--;
		}
		else
		{
			cout << "Can't move that way" << endl;
		}
		break;
	case 4://south
		if (y < 5)
		{
			y++;
		}
		else
		{
			cout << "Can't move that way" << endl;
		}
		
		break;
	case 5://east
		if (x <3)
		{
			x++;
		}
		else
		{
			cout << "Can't move that way" << endl;
		}
		
		break;
	case 6://west
		if (x>0)
		{
			x--;
		}
		else
		{
			cout << "Can't move that way" << endl;
		}
		
		break;
	case 7:
		encounter = true;
		break;
	case 0:
		running = false;
		break;
	default:
		cout << "!!!<INVALID ENTRY>!!!" << endl;
		break;
	}
}
void Game::Area()
{
	switch (map->GetArea())
	{
	case 1:
		cout << "You are stood near a river" << endl;
		break;
	case 2:
		cout << "You are stood in a forest" << endl;
		break;
	case 3:
		cout << "You arrive at a ruined fort" << endl;
		break;
	case 4:
		cout << "You are in a clearing of a forest" << endl;
		break;
	case 5:
		cout << "You stand in a town square of a dilapidated town" << endl;
		break;
	case 6:
		cout << "The air gets cold as you enter the room and blood drips from the roof " << endl;
		break;
	case 7:
		cout << "You stand in a cave with skeletons littering the floor" << endl;
		break;
	case 8:
		cout << "You have entered an old Castle" << endl;
		break;
	case 9:
		cout << "You stand in an enormous cave" << endl;
		break;

	}
}
void Game::Encounter()
{
	switch (map->GetArea()) // checks what area you are in then sets the stats for the enemy
	{
	case 1:
	{
		if (player->CheckInv("Shield") == false) 
		{
			Enemy goblin(18, 10, 2, 2, 1, "Goblin", 1);
			*enemy = goblin;
		}
		else if (enemy->IsAlive() == true && player->CheckInv("Shield") == true)
		{
			enemy->Kill();
			cout << "Enemy is already dead" << endl;
			system("pause");
		}
		else
		{
			cout << "Enemy is already dead" << endl;
			system("pause");
		}
	}
		break;
	case 2:
	{
		if (player->CheckInv("Axe") == false)
		{
			Enemy orc(20, 11, 1, 3, 1, "Orc", 1);
			*enemy = orc;
		}
		else if (enemy->IsAlive() == true && player->CheckInv("Axe") == true)
		{
			enemy->Kill();
			cout << "Enemy is already dead" << endl;
			system("pause");
		}
		else
		{
			cout << "Enemy is already dead" << endl;
			system("pause");
		}
		
	}
		break;
	case 3:
	{
		if (player->CheckInv("Amulet") == false)
		{
			Enemy troll(18, 16, 2, 3, 1, "Troll", 1);
			*enemy = troll;
		}
		else if (enemy->IsAlive() == true && player->CheckInv("Amulet") == true)
		{
			enemy->Kill();
			cout << "Enemy is already dead" << endl;
			system("pause");
		}
		else
		{
			cout << "Enemy is already dead" << endl;
			system("pause");
		}
		
	}
		break;
		
	case 4:
	{
		if (player->CheckInv("Enchanted Sword") == false)
		{
			Enemy ogre(20, 16, 3, 3, 1, "Ogre", 1);
			*enemy = ogre;
		}
		else if (enemy->IsAlive() == true && player->CheckInv("Enchanted Sword") == true)
		{
			enemy->Kill();
			cout << "Enemy is already dead" << endl;
			system("pause");
		}
		else
		{
			cout << "Enemy is already dead" << endl;
			system("pause");
		}
	}
		break;
	case 5:
	{
		if (player->CheckInv("Full Plate") == false)
		{
			Enemy knight(22, 14, 3, 3, 1, "Black Knight", 1);
			*enemy = knight;
		}
		else if (enemy->IsAlive() == true && player->CheckInv("Full Plate") == true)
		{
			enemy->Kill();
			cout << "Enemy is already dead" << endl;
			system("pause");
		}
		else
		{
			cout << "Enemy is already dead" << endl;
			system("pause");
		}
	}
		break;
	case 6:
	{
		if (player->CheckInv("Goblet") == false)
		{
			Enemy vampire(20, 21, 3, 4, 2, "Vampire", 1);
			*enemy = vampire;
		}
		else if (enemy->IsAlive() == true && player->CheckInv("Goblet") == true)
		{
			enemy->Kill();
			cout << "Enemy is already dead" << endl;
			system("pause");
		}
		else
		{
			cout << "Enemy is already dead" << endl;
			system("pause");
		}
	}
		break;
	case 7:
	{
		if (player->CheckInv("Shin Bone") == false)
		{
			Enemy necromancer(18, 16, 4, 4, 2, "Necromancer", 1);
			*enemy = necromancer;
		}
		else if (enemy->IsAlive() == true && player->CheckInv("Shin Bone") == true)
		{
			enemy->Kill();
			cout << "Enemy is already dead" << endl;
			system("pause");
		}
		else
		{
			cout << "Enemy is already dead" << endl;
			system("pause");
		}
	}
		break;
	case 8:
	{
		if (player->CheckInv("Poison") == false)
		{
			Enemy chimera(20, 18, 3, 4, 1, "Chimera", 1);
			*enemy = chimera;
		}
		else if (enemy->IsAlive() == true && player->CheckInv("Poison") == true)
		{
			enemy->Kill();
			cout << "Enemy is already dead" << endl;
			system("pause");
		}
		else
		{
			cout << "Enemy is already dead" << endl;
			system("pause");
		}
	}
		break;
	case 9:
	{
		if (player->CheckInv("Key") == false)
		{
			Enemy dragon(22, 21, 5, 5, 1, "Dragon", 1);
			*enemy = dragon;
		}
		else if (enemy->IsAlive() == true && player->CheckInv("Key") == true)
		{
			enemy->Kill();
			cout << "Enemy is already dead" << endl;
			system("pause");
		}
		else
		{
			cout << "Enemy is already dead" << endl;
			system("pause");
		}
	}
		break;

	}

	while (enemy->IsAlive())// loop for combat
	{
		EncounterMenu();
		EncounterInput();
		EnemyTurn();
		if (player->IsAlive() == false)
		{
			Dead();
		}

	}
	switch (map->GetArea())// chooses which item the player recieves on an enemies death dependant on the area the player is in
	{
	case 1:
	{
		player->AddToInv("Shield");
		player->SetAC(2);
	}
		break;
	case 2:
	{
		player->AddToInv("Axe");
		player->SetAttack(1);
		player->SetDamage(1);
	}
		break;
	case 3:
	{
		player->AddToInv("Amulet");
		player->SetHealth(5);
	}
		break;
	case 4:
	{
		player->AddToInv("Enchanted Sword");
		player->SetAttack(3);
		player->SetDamage(2);
	}
		break;
	case 5:
	{
		player->AddToInv("Full Plate");
		player->SetAC(5);
	}
		break;
	case 6:
	{
		player->AddToInv("Goblet");
		player->SetDamage(1);
		player->SetHealth(3);
	}
		break;
	case 7:
	{
		player->AddToInv("Shin Bone");
		player->SetAC(1);
		player->SetAttack(1);
	}
		break;
	case 8:
	{
		player->AddToInv("Poison");
		player->SetDamage(2);
	}
		break;
	case 9:
	{
		player->AddToInv("Key");
		
	}
		break;

	}
	encounter = false;
	
}
void Game::EncounterInput() // takes input from the player for the menu when in an encounter
{
	switch (choice)
	{
	case 1:
		player->DisplayStats();
		break;
	case 2:
		player->DisplayInv();
		break;
	case 3:
		if (player->Attack() >= enemy->GetAC())
		{
			enemy->Hit(player->GetDam());
		}
		else
		{
			cout << "You Missed" << endl;
		}
		break;
	case 4:
		player->UsePotion();
		break;
	case 5:
		player->Special1();
		break;
	case 6:
		if (player->Special2() >= enemy->GetAC())
		{
			enemy->Hit(player->GetDam());
		}
		else
		{
			cout << "You Missed" << endl;
		}
		break;

	case 0:
		running = false;
		break;
	default:
		cout << "!!!<INVALID ENTRY>!!!" << endl;
		break;
	}
}
void Game::Win()
{
	system("cls");
	cout << "YOU WON THE GAME" << endl;
	system("pause");
	running = false;
}
void Game::Dead()
{
	system("cls");
	cout << "YOU DIED" << endl;
	system("pause");
	running = false;
}
Game::~Game()
{
	delete player;
	delete enemy;
}