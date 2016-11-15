//
// Created by Matthew Jones on 11/14/16.
//

#ifndef FINAL_PARSER_H
#define FINAL_PARSER_H


#include <vector>
#include "Word.h"

class Parser {
public:
	Parser();
	std::vector<Word> parse(std::string fileName);
private:
	std::vector<Word> parseWordByWord(std::string text);
	bool startsNewword(char c) const;
};


#endif //FINAL_PARSER_H
