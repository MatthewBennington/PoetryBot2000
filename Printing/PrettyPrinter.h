//
// Created by Matthew Jones on 11/21/16.
//

#ifndef FINAL_PRINTER_H
#define FINAL_PRINTER_H

#include <vector>
#include "../Word.h"
#include "../WordVector.h"


class PrettyPrinter {
public:
	PrettyPrinter(WordVector w);
	std::string print();
	std::string print(int ammount);
	std::string print(int ammount, int delay);
private:
	WordVector words;
};


#endif //FINAL_PRINTER_H
