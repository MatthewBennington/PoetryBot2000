//
// Created by Matthew Jones on 11/28/16.
//

#ifndef FINAL_PARSEDTEXTPARSER_H
#define FINAL_PARSEDTEXTPARSER_H


#include "Parser.h"
#include "../lib/json.hpp"

class ParsedTextParser: public Parser {
public:
	ParsedTextParser();
	virtual WordVector parse();
private:
	void parseJSON(std::string text);
	void populateVector();
	nlohmann::json stringToJson(std::string str);
};


#endif //FINAL_PARSEDTEXTPARSER_H
