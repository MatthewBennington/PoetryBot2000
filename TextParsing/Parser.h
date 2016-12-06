//
// Created by Matthew Jones on 11/18/16.
//

#ifndef FINAL_PARSER_H
#define FINAL_PARSER_H

#include <fstream>
#include "../Word.h"
#include "../WordVector.h"

class Parser {
public:
	virtual WordVector parse() = 0;
	void loadFile(std::string file) {
		fileName = file;
		fileLoaded = true;
	}
protected:
	WordVector words;
	std::string fileName;
	bool fileLoaded = false;
	std::string consumeFile(std::string FileName) {
		std::string rval;
		std::string line;
		std::ifstream fileToParse(fileName);
		if(fileToParse.is_open()) {
			while(getline(fileToParse, line)) {
				rval += (line + "\n");
			}
			fileToParse.close();
		} else {
			throw std::invalid_argument("could not open file: " + fileName);
		}
		return rval;
	}
};

#endif //FINAL_PARSER_H
