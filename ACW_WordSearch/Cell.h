#pragma once
#include <fstream>
class Cell
{
	Cell* adjacentCells[8] = { nullptr };
	char letter;


public:
    const char Letter() const;
	void Letter(const char l);
	Cell();
	~Cell();
	Cell(const Cell &cell);
	Cell& operator=(Cell &cell);
	void linkCell(Cell * const cell, const int &direction);
	Cell* GetCell(const int &direction) const;
};

