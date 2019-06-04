#include <iostream>
#include <stdlib.h>
#include <string>
#include "Game.h"
#include "Cat.h"

using namespace std;

//Cat* cat = new Cat(20,"Bob");
//Cat* a_cat = new Cat();
//Cat* the_cat = new Cat(1, "Mr Tibbles");
//
//bool cats = true;

//void AnimalFarm()
//{
//	Cat catstack;
//	Cat copyCat1(catstack);
//	Cat copyCat;
//	copyCat = catstack;
//	/*while (cats)
//	{
//
//		Cat::ShowCount();
//		cat->DisplayCat();
//		a_cat->DisplayCat();
//		the_cat->DisplayCat();
//
//		system("pause");
//
//		cats = false;
//	}
//	delete cat;
//	delete a_cat;
//	delete the_cat;*/
//	copyCat.DisplayCat();
//	copyCat1.DisplayCat();
//	Cat::ShowCount();
//	system("pause");
//}
int main()
{
	 //My Game /////////////
	Game* game = new Game();
	game->Initialize();
	game->RunGame();
	delete game;
	////////////////////////
	
	/*AnimalFarm();
	Cat::ShowCount();
	system("pause");*/
	return 0;
}