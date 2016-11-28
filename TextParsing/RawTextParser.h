//
// Created by Matthew Jones on 11/14/16.
//

#ifndef FINAL_RAWTEXTPARSER_H
#define FINAL_RAWTEXTPARSER_H


#include <vector>
#include "../Word.h"
#include "Parser.h"

class RawTextParser: public Parser {
public:
	RawTextParser();
	virtual WordVector parse();
private:
	std::string mateenUlhaqReplace(std::string &s, const std::string &toReplace, const std::string &replaceWith);
	virtual std::string consumeFile(std::string FileName);
	void parseWordByWord(std::string text);
	bool startsNewWord(std::string text, int &index);
};


#endif //FINAL_PARSER_H
