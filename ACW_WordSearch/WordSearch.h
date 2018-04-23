#pragma once
#include <vector>
#include <string>

class WordSearch {
	const char* puzzleName = "wordsearch_grid.txt";
	const char* dictionaryName = "dictionary.txt";

	char simpleGrid[9][9];
	std::vector<std::string> simpleDictionary;


	// Add your code here

public:
	explicit WordSearch(const char * const filename);
	~WordSearch();

	void ReadSimplePuzzle();
	void ReadSimpleDictionary();
	void ReadAdvancedPuzzle();
	void ReadAdvancedDictionary();
	void SolvePuzzleSimple();
	void SolvePuzzleAdvanced();
	void WriteResults(const	double loadTime, const double solveTime) const;
	
	// Add your code here
};

