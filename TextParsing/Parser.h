//
// Created by Matthew Jones on 11/18/16.
//

#ifndef FINAL_PARSER_H
#define FINAL_PARSER_H

#include "../Word.h"

class Parser {
public:
	virtual std::vector<Word*> parse() = 0;
	void loadFile(std::string file) {
		fileName = file;
		fileLoaded = true;
	}
protected:
	std::vector<Word*> words;
	std::string fileName;
	bool fileLoaded = false;
	virtual std::string consumeFile(std::string FileName) = 0; //TODO Should this be defined here?
};

#endif //FINAL_PARSER_H
