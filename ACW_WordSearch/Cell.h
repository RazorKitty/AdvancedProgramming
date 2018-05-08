#pragma once
#include <fstream>
class Cell
{
	char letter;
	Cell* agacentCells[8] = {nullptr};

public:
    const char& Letter();
	void Letter(char l);
	Cell();
	~Cell();
	void linkCell(Cell *cell, const int &direction);
	Cell* GetCell(const int &direction);
	friend std::fstream& operator>>(std::fstream& fs, Cell cell);
};

