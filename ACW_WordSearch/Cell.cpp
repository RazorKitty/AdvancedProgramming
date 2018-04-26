#include "Cell.h"
#include <fstream>
const char& Cell::Letter()
{
	return letter;
}

void Cell::Letter(char l) {
	letter = l;
}

Cell::Cell() : letter(0), NW(0), N(0), NE(0), E(0), SE(0), S(0), SW(0), W(0) {}

Cell::~Cell() {}

void Cell::SetWest(Cell *cell) {
	W = cell;
	cell->E = this;
}

void Cell::SetNorth(Cell *cell) {
	N = cell;
	cell->S = this;
}

void Cell::SetNorthWest(Cell *cell) {
	NW = cell;
	cell->SE = this;
}

std::fstream & Cell::operator>>(std::fstream & is)
{
	is >> letter;
	return is;
}

