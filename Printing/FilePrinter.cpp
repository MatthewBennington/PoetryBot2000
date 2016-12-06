//
// Created by Matthew Jones on 11/28/16.
//

#include <fstream>
#include "FilePrinter.h"

using std::string;
using json = nlohmann::json;

FilePrinter::FilePrinter(WordVector w): words(w){}

void FilePrinter::print(string outPath) {
	std::ofstream outFile;
	outFile.open(outPath);
	outFile << convertToS() << std::endl;
	outFile.close();
}

std::string FilePrinter::convertToS() {
	return convertToJSON().dump();
}

json FilePrinter::convertToJSON() {
	json rval;
	for(int i = 0; i < words.dumpWords().size(); i++) {
		rval.push_back(words.dumpWords()[i]->toJSON());
	}
	return rval;
}
