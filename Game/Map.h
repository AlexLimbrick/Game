#pragma once
#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

enum Cave { North_West = 1, North, North_East, West, Centre, East, South_West, South_East, South };

class Map
{
public:
	Map();
	~Map();
	void drawMap();
	void update(int x, int y);
	int GetArea() {return playerPosition; }//1 = north west, 2 = north 3, = north east, 4 = west, 5 = centre, 6 = east, 7 = south west, 8 = south, 9 = south east
private:
	Cave cave[3][3];

	Cave playerPosition = North;
	int PRow; // player row
	int PColumn; // player column
	

};

