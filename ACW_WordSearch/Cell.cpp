#include "Cell.h"
#include <fstream>
const char Cell::Letter() const
{
	return letter;
}

void Cell::Letter(const char l) {
	letter = l;
}

Cell::Cell() : letter('\0'), agacentCells{ {nullptr} } {}

Cell::~Cell() {
	//for (int i = 0; i < 8; i++)
	//{
	//	if (agacentCells[i])
	//		delete &agacentCells[i];
	//}
}

void Cell::linkCell(Cell * cell, const int & direction) {
	agacentCells[direction] = cell;
}

Cell* Cell::GetCell(const int &direction) const {
		return agacentCells[direction];
}

