//
// Created by Matthew Jones on 11/14/16.
//

#include "Parser.h"
#include <fstream>

Parser::Parser() {

}

std::string consumeFile(std::string fileName) {
	std::string rval;
	std::string line;
	std::ifstream fileToParse(fileName);
	if(fileToParse.is_open()) {
		while(getline(fileToParse, line)) {
			rval += (line + "\n";
		}
		fileToParse.close();
	} else {
		throw std::invalid_argument("could not open file: " + fileName);
	}
	return rval;
}

std::vector<Word> Parser::parseWordByWord(std::string text) {
	char c;
	while
}

std::vector<Word> Parser::parse(std::string fileName) {
	return parseWordByWord(consumeFile(fileName));

}

bool Parser::startsNewword(char c) const {
	return false;
}

