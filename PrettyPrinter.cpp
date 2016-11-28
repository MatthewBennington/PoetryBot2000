//
// Created by Matthew Jones on 11/21/16.
//

#include <cstdlib>
#include "PrettyPrinter.h"

std::string PrettyPrinter::print() {
	return print(500, 0);
}

PrettyPrinter::PrettyPrinter(WordVector w): words(w){}

std::string PrettyPrinter::print(int ammount, int delay) {
	std::string rval;
	Word* word = words.getRandWord();
	for(int i = 0; i < ammount; i++) {
		rval += " " + word->getWord();
		word = word->getRandWordFollowing();
		sleep(delay);
	}
	return rval;
}

std::string PrettyPrinter::print(int ammount) {
	return print(ammount, 0);
}
