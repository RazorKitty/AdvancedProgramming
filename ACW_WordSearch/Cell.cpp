#include "Cell.h"
#include <fstream>
const char Cell::Letter() const
{
	return letter;
}

void Cell::Letter(const char l) {
	letter = l;
}

Cell::Cell() : adjacentCells{ {nullptr} }, letter('\0') {}

Cell::~Cell() {
}

void Cell::linkCell(Cell *  const cell, const int & direction) {
	adjacentCells[direction] = cell;
}

Cell* Cell::GetCell(const int &direction) const {
		return adjacentCells[direction];
}

