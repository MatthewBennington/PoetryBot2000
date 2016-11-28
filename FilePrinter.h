//
// Created by Matthew Jones on 11/28/16.
//

#ifndef FINAL_FILEPRINTER_H
#define FINAL_FILEPRINTER_H


#include "WordVector.h"
#include "lib/json.hpp"

class FilePrinter {
public:
	FilePrinter(WordVector w);
	void print(std::string outPath);
private:
	WordVector words;
	std::string convertToS();
	nlohmann::json convertToJSON();
};


#endif //FINAL_FILEPRINTER_H
