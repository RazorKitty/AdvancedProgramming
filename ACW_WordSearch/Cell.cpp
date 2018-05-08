#include "Cell.h"
#include <fstream>
const char& Cell::Letter()
{
	return letter;
}

void Cell::Letter(char l) {
	letter = l;
}

Cell::Cell() : letter('\0'), agacentCells{ {nullptr} } {}

Cell::~Cell() {
	for (int i = 0; i < 8; i++)
	{
		delete agacentCells[i];
	}
}

void Cell::linkCell(Cell * cell, const int & direction) {
	agacentCells[direction] = cell;
}

Cell* Cell::GetCell(const int &direction) {
	//return agacentCells[direction];
		return agacentCells[direction];

}

std::fstream & operator>>(std::fstream & fs, Cell cell) {
	fs >> cell.letter;
	return fs;
}
