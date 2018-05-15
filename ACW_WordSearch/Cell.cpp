#include "Cell.h"
#include <fstream>
const char Cell::Letter() const
{
	return letter;
}

void Cell::Letter(const char l) {
	letter = l;
}

Cell::Cell() : agacentCells{ {nullptr} }, letter('\0') {}

Cell::~Cell() {
}

void Cell::linkCell(Cell *  const cell, const int & direction) {
	agacentCells[direction] = cell;
}

Cell* Cell::GetCell(const int &direction) const {
		return agacentCells[direction];
}

