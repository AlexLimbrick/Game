#include "Map.h"



Map::Map()
{
	
	cave[0][0] = North_West;
	cave[0][1] = North;
	cave[0][2] = North_East;
	cave[1][0] = West;
	cave[1][1] = Centre;
	cave[2][1] = East;
	cave[0][2] = South_West;
	cave[1][2] = South;
	cave[2][2] = South_East;
}


Map::~Map()
{
}

void Map::drawMap() // draws the map
{
	string map[7][3] =
	{
		{ "<><><><><><>","<><><><><>","<><><><><><><><><><>" },
		{ "< north west >","<   north    >","< north east >" },
		{ "<><><><><><>","<><><><><>","<><><><><><><><><><>" },
		{ "<    west    >","<   centre   >","<    east    >" },
		{ "<><><><><><>","<><><><><>","<><><><><><><><><><>" },
		{ "< south west >","<   south    >","< south east >" },
		{ "<><><><><><><><><><><><>","<><><><>","<><><><><>", },

	};



	map[PRow][PColumn] = "<      p     >";
	


	for (int i = 0; i<7; i++)    //This loops on the rows.
	{
		for (int j = 0; j<3; j++) //This loops on the columns
		{
			cout << map[i][j];
		}
		cout << endl;
	}
}

void Map::update(int x, int y) // updates the players position on the map
{
	playerPosition = cave[y][x];
	switch (playerPosition)
	{
	case North_West:


		PRow = 1;
		PColumn = 0;

		break;
	case North:


		PRow = 1;
		PColumn = 1;

		break;
	case North_East:


		PRow = 1;
		PColumn = 2;

		break;
	case West:


		PRow = 3;
		PColumn = 0;

		break;
	case Centre:


		PRow = 3;
		PColumn = 1;

		break;
	case East:


		PRow = 3;
		PColumn = 2;

		break;
	case South_West:


		PRow = 5;
		PColumn = 0;

		break;
	case South:


		PRow = 5;
		PColumn = 1;

		break;
	case South_East:


		PRow = 5;
		PColumn = 2;

		break;
	default:
		break;


	}
}

