#include "WordSearch.h"
#include <iostream>
#include <fstream>
using namespace std;

WordSearch::WordSearch(const char * const filename) {
	// Add your code here
}

WordSearch::~WordSearch() {
	// Add your code here
}

void WordSearch::ReadSimplePuzzle() {
	// Add your code here
	fstream file(puzzleName);
	int length;
	if (file.is_open())
	{
		file >> length;
		for (int y = 0; y < 9; y++)
		{
			for (int x = 0; x < 9; x++)
			{
				file >> simpleGrid[y][x];
			}
		}
	}
	// grid is loaded	
}

void WordSearch::ReadSimpleDictionary() {
	// Add your code here
	fstream file(dictionaryName);
	if (file.is_open())
	{
		string line;
		while (!file.eof())
		{
			file >> line;
			simpleDictionary.push_back(line);
		}
	}
	//dictionary loaded
}

void WordSearch::ReadAdvancedPuzzle() {
	// Add your code here
}

void WordSearch::ReadAdvancedDictionary() {
	// Add your code here
}

void WordSearch::SolvePuzzleSimple() {
	// Add your code here

}

void WordSearch::SolvePuzzleAdvanced() {
	// Add your code here
}

void WordSearch::WriteResults(const double loadTime, const double solveTime) const {
	// Add your code here
}
