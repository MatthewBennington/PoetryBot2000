//
// Created by Matthew Jones on 11/14/16.
//

#ifndef FINAL_PARSER_H
#define FINAL_PARSER_H


#include <vector>
#include "../Word.h"
#include "Parser.h"

class RawTextParser: public Parser {//FIXME What is wrong here?
public:
	RawTextParser(std::string file);
	std::vector<Word> parse();
private:
	std::vector<Word> words;
	std::string text;
	std::string consumeFile(std::string FileName);
	void parseWordByWord(std::string text);
	bool startsNewWord(std::string text, int &index);
	bool containsStr(std::string str) const;
	void addWord(std::string word, Word lastWord);
	Word getWord( std::string str) const;
	int getIndexForWord(std::string str, int begin, int end) const;
	void addToV(Word word);
};


#endif //FINAL_PARSER_H
