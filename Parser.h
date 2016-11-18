//
// Created by Matthew Jones on 11/18/16.
//

#ifndef FINAL_PARSER_H
#define FINAL_PARSER_H

#include "Word.h"

class Parser {
public:
	virtual std::vector<Word> parse() = 0;
};

#endif //FINAL_PARSER_H
