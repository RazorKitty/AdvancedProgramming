#include "WordSearch.h"
#include <iostream>
#include <fstream>
using namespace std;

WordSearch::WordSearch(const char * const filename) {
	outputFile = filename;
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
	foundWords.reserve(simpleDictionary.size());
	//dictionary loaded
}

void WordSearch::ReadAdvancedPuzzle() {
	// Add your code here
}

void WordSearch::ReadAdvancedDictionary() {
	// Add your code here
}

void WordSearch::SolvePuzzleSimple() {
	for (int word = 0; word < simpleDictionary.size(); word++)
	{
		for (int y = 0; y < 9; y++)
		{
			for (int x = 0; x < 9; x++)
			{
				//we found the first character
				if (simpleGrid[y][x] == simpleDictionary[word][0])
				{
					// now we have to match the rest
					// pick a direction
					for (int direction = 0; direction < 8; direction++)
					{
						int _y = y;
						int _x = x;
						for (int letter = 1; letter < simpleDictionary[word].size(); letter++)
						{
							_y += directionalOffSets[direction][0];
							_x += directionalOffSets[direction][1];
							// bounds checking
							if (_y < 0 || _x < 0)
								goto NextDirection;
							if (simpleGrid[_y][_x] != simpleDictionary[word][letter])
								goto NextDirection;
							// keep going till we finish the word
							if (letter + 1 == (int)simpleDictionary[word].size())
							{// we have the word!!
								foundWords.push_back(FoundWord(simpleDictionary[word], y, x));
								goto NextWord;
							}
						}
					NextDirection:
						continue;
					}
				}
			}
		}
	NextWord:
		continue;
	}
	// Add your code here

}

void WordSearch::SolvePuzzleAdvanced() {
	// Add your code here
}

void WordSearch::WriteResults(const double loadTime, const double solveTime) const {
	// Add your code here
	cout << "NUMBER_OF_WORDS_MATCHED " << foundWords.size() + 1 << endl;
	cout << "WORDS_MATCHED_IN_GRID" << endl;
	for (int i = 0; i < foundWords.size(); i++)
	{
		cout << foundWords[i].startX << " " << foundWords[i].startY << " " << foundWords[i].word << endl;
	}
	cout << "TIME_TO_POPULATE_GRID_STRUCTURE " << loadTime << endl;
	cout << "TIME_TO_SOLVE_PUZZLE " << solveTime << endl;

}
