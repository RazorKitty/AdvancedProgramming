#pragma once
#include <vector>
#include <string>
#include "Cell.h"

struct Word {
	std::string word;
	int y;
	int x;
	explicit Word(std::string &wordin) : word(wordin), y(-1), x(-1) {}
};

class WordSearch {

	std::vector<Word> simpleDictionary;
	const int directionalOffSets[8][2]{
		{ -1, -1 },		//NW
		{ -1, 0 },		//N
		{ -1, 1 },		//NE
		{ 0, 1 },		//E
		{ 1, 1 },		//SE
		{ 1, 0 },		//S
		{ 1, -1 },		//SW
		{ 0, -1 }		//W
	};
	Cell** advancedGrid;
	char** simpleGrid;
	const char* puzzleName = "wordsearch_grid.txt";
	const char* dictionaryName = "dictionary.txt";
	const char* outputFile;
	int gridSize;
	int cellVisits = 0;
	int dictionaryVisits = 0;

	// Add your code here

public:
	explicit WordSearch(const char * const filename);
	~WordSearch();
	WordSearch& operator=(WordSearch& wordSearch);
	WordSearch(const WordSearch& wordSearch);
	void ReadSimplePuzzle();
	void ReadSimpleDictionary();
	void ReadAdvancedPuzzle();
	void ReadAdvancedDictionary() const;
	void SolvePuzzleSimple();
	void SolvePuzzleAdvanced();
	void WriteResults(const	double loadTime, const double solveTime) const;
	
	// Add your code here
};

