#include "WordSearch.h"
#include "Cell.h"
#include <iostream>
#include <fstream>
using namespace std;

WordSearch::WordSearch(const char * const filename) : advancedGrid(nullptr), simpleGrid(nullptr), outputFile(filename), gridSize(0) {
	
}

WordSearch::~WordSearch() {
	if (advancedGrid)
	{
		for (int y = 0; y < gridSize; ++y)
		{
			delete[] advancedGrid[y];
		}
		delete[] advancedGrid;
	}
	
	if (simpleGrid)
	{
		for (int y = 0; y < gridSize; ++y)
		{
			delete simpleGrid[y];
		}
		delete[] simpleGrid;
	}
}

void WordSearch::ReadSimplePuzzle() {
	fstream file(puzzleName);

	file >> gridSize;
	simpleGrid = new char*[gridSize];
	for (int y = 0; y < gridSize; ++y)
	{
		simpleGrid[y] = new char[gridSize];
		for (int x = 0; x < gridSize; ++x)
		{
			file >> simpleGrid[y][x];
		}
	}	
}

void WordSearch::ReadSimpleDictionary() {
	fstream file(dictionaryName);
	string line;
	while (!file.eof())
	{
		file >> line;
		simpleDictionary.push_back(Word(line));
	}
}

void WordSearch::ReadAdvancedPuzzle() {
	fstream file(puzzleName);
	file >> gridSize;
	advancedGrid = new Cell*[gridSize];
	for (int y = 0; y < gridSize; ++y)
		advancedGrid[y] = new Cell[gridSize];

	for (int y = 0; y < gridSize; ++y)
	{
		for (int x = 0; x < gridSize; ++x)
		{
			char tmp;
			file >> tmp;
			advancedGrid[y][x].Letter(tmp);
			for (int direction = 0; direction < 8; ++direction)
			{
				const int _y = y + directionalOffSets[direction][0];
				const int _x = x + directionalOffSets[direction][1];
				if (-1 < _y && _y < gridSize && -1 < _x && _x < gridSize)
					advancedGrid[y][x].linkCell(&advancedGrid[_y][_x], direction);
				else
					advancedGrid[y][x].linkCell(nullptr, direction);
			}
		}
	}

}

void WordSearch::ReadAdvancedDictionary() const {
	cout << "THIS METHOD IS NOT IMPLEMETED" << endl;
}

void WordSearch::SolvePuzzleSimple() {
	for (int word = 0; word < simpleDictionary.size(); ++word) {
		dictionaryVisits++;
		for (int y = 0; y < gridSize; ++y) {
			for (int x = 0; x < gridSize; ++x) {
				++cellVisits;
				if (simpleGrid[y][x] == simpleDictionary[word].word[0]) {
					for (int direction = 0; direction < 8; ++direction) {
						int _y = y;
						int _x = x;
						for (int letter = 1; letter < simpleDictionary[word].word.size(); ++letter) {
							_y += directionalOffSets[direction][0];
							_x += directionalOffSets[direction][1];
							if (gridSize <= _y || _y < 0 || gridSize <= _x || _x < 0 || cellVisits++ && simpleGrid[_y][_x] != simpleDictionary[word].word[letter])
								goto NextDirection;
						}
						simpleDictionary[word].y = y;
						simpleDictionary[word].x = x;
						goto NextWord;

					NextDirection:
						continue;
					}
				}
			}
		}
	NextWord:
		continue;
	}
}




void WordSearch::SolvePuzzleAdvanced() {
	for (int word = 0; word < simpleDictionary.size(); ++word) {
		++dictionaryVisits;
		for (int y = 0; y < gridSize; ++y) {
			for (int x = 0; x < gridSize; ++x) {
				++cellVisits;
				if (simpleDictionary[word].word[0] == advancedGrid[y][x].Letter()) {
					for (int direction = 0; direction < 8; ++direction) {
						Cell* cell = &advancedGrid[y][x];
						for (int letter = 1; letter < simpleDictionary[word].word.size(); ++letter) {
							cell = cell->GetCell(direction);
							if (!cell || (++cellVisits && cell->Letter() != simpleDictionary[word].word[letter]))
								goto NextDirection;
						}
						simpleDictionary[word].y = y;
						simpleDictionary[word].x = x;
						goto NextWord;
					NextDirection:
						continue;
					}
				}
			}

		}
	NextWord:
		continue;
	}
}

void WordSearch::WriteResults(const double loadTime, const double solveTime) const {
	fstream file(outputFile, ios::out);

	int wordsFound = 0;
	for (int i = 0; i < simpleDictionary.size(); ++i)
		if (simpleDictionary[i].x > -1)
			++wordsFound;
	file << "NUMBER_OF_WORDS_MATCHED " << wordsFound << endl << endl;

	file << "WORDS_MATCHED_IN_GRID" << endl;
	for (int i = 0; i < simpleDictionary.size(); ++i)
		if (simpleDictionary[i].x > -1)
			file << simpleDictionary[i].x << " " << simpleDictionary[i].y << " " << simpleDictionary[i].word << endl;
	file << endl;
	file << "WORDS_UNMATCHED_IN_GRID" << endl;
	for (int i = 0; i < simpleDictionary.size(); ++i)
		if (simpleDictionary[i].x < 0)
			file << simpleDictionary[i].word << endl;
	file << endl;
	file << "NUMBER_OF_GRID_CELLS_VISITED " << cellVisits << endl << endl;
	file << "NUMBER_OF_DICTIONARY_ENTRIES_VISITED " << dictionaryVisits << endl << endl;
	file << "TIME_TO_POPULATE_GRID_STRUCTURE " << loadTime << endl << endl;
	file << "TIME_TO_SOLVE_PUZZLE " << solveTime << endl;


}
