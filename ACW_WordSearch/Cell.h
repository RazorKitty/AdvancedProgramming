#pragma once
#include <fstream>
class Cell
{
	char letter;
	Cell* NW;
	Cell* N;
	Cell* NE;
	Cell* E;
	Cell* SE;
	Cell* S;
	Cell* SW;
	Cell* W;

public:
    const char& Letter();
	void Letter(char l);
	Cell();
	~Cell();
	void SetWest(Cell *cell);
	void SetNorth(Cell *cell);
	void SetNorthWest(Cell *cell);

	std::fstream & operator>>(std::fstream & is);
};

