#include "WordSearch.h"
#include "Cell.h"
#include <iostream>
#include <fstream>
using namespace std;

WordSearch::WordSearch(const char * const filename) : outputFile(filename)
{
	// Add your code here
}

WordSearch::~WordSearch() {
	// Add your code here
}

void WordSearch::ReadSimplePuzzle() {
	// Add your code here
	fstream file(puzzleName);
	int length;

	file >> length;
	for (int y = 0; y < 9; y++)
	{
		for (int x = 0; x < 9; x++)
		{
			file >> simpleGrid[y][x];
		}
	}
	//file.close();

	// grid is loaded	
}

void WordSearch::ReadSimpleDictionary() {
	// Add your code here
	fstream file(dictionaryName);
	string line;
	while (!file.eof())
	{
		file >> line;
		simpleDictionary.push_back(Word(line));
	}
	//file.close();

	//foundWords.reserve(simpleDictionary.size());
	//dictionary loaded
}

void WordSearch::ReadAdvancedPuzzle() {
	// Add your code here
	fstream file(puzzleName);
	int length;
	file >> length;
	advancedGrid = new Cell*[length];
	for (int i = 0; i < length; i++)
	{
		advancedGrid[i] = new Cell[length];
	}
	for (int y = 0; y < length; y++)
	{
		for (int x = 0; x < length; x++)
		{
			//file >> advancedGrid[y][x];
		}
	}

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
				cellVisits++;
				dictionaryVisits++;
				//we found the first character
				if (simpleGrid[y][x] == simpleDictionary[word].word[0])
				{
					// now we have to match the rest
					// pick a direction
					for (int direction = 0; direction < 8; direction++)
					{
						int _y = y;
						int _x = x;
						dictionaryVisits++;
						for (int letter = 1; letter < simpleDictionary[word].word.size(); letter++)
						{
							_y += directionalOffSets[direction][0];
							_x += directionalOffSets[direction][1];
							// bounds checking
							if (_y < 0 || _x < 0)
								goto NextDirection;
							cellVisits++;
							dictionaryVisits++;
							if (simpleGrid[_y][_x] != simpleDictionary[word].word[letter])
								goto NextDirection;
							// keep going till we finish the word
							dictionaryVisits++;
							if (letter + 1 == simpleDictionary[word].word.size())
							{// we have the word!!
								//foundWords.push_back(FoundWord(simpleDictionary[word], y, x));
								simpleDictionary[word].y = y;
								simpleDictionary[word].x = x;
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
	cout << "NUMBER_OF_WORDS_MATCHED " << "" << endl;
	cout << "WORDS_MATCHED_IN_GRID" << endl;
	cout << "NUMBER_OF_GRID_CELLS_VISITED " << cellVisits << endl;
	cout << "TIME_TO_POPULATE_GRID_STRUCTURE " << loadTime << endl;
	cout << "TIME_TO_SOLVE_PUZZLE " << solveTime << endl;
	cout << "NUMBER_OF_DICTIONARY_ENTRIES_VISITED " << dictionaryVisits << endl;

}
