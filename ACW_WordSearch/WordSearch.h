#pragma once
#include <vector>
#include <string>

struct FoundWord {
	std::string& word;
	int startY;
	int startX;
	FoundWord();
	FoundWord(std::string& wordIn, const int startYIn, const int startXIn) :
		word(wordIn),
		startY(startYIn),
		startX(startXIn) {}
};

class WordSearch {

	std::vector<std::string> simpleDictionary;
	std::vector<FoundWord> foundWords;
	const int directionalOffSets[8][2]{
		{ -1, -1 },	//NW
		{ -1, 0 },	//N
		{ -1, 1 },	//NE
		{ 0, 1 },		//E
		{ 1, 1 },		//SE
		{ 1, 0 },		//S
		{ 1, -1 },	//SW
		{ 0, -1 }		//W
	};

	char simpleGrid[9][9] = {};
	const char* puzzleName = "wordsearch_grid.txt";
	const char* dictionaryName = "dictionary.txt";
	const char* outputFile;









	// Add your code here

public:
	explicit WordSearch(const char * const filename);
	~WordSearch();
	WordSearch& operator=(WordSearch&);
	void ReadSimplePuzzle();
	void ReadSimpleDictionary();
	void ReadAdvancedPuzzle();
	void ReadAdvancedDictionary();
	void SolvePuzzleSimple();
	void SolvePuzzleAdvanced();
	void WriteResults(const	double loadTime, const double solveTime) const;
	
	// Add your code here
};

