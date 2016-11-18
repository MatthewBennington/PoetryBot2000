//
// Created by Matthew Jones on 11/14/16.
//

#include <cstdlib>
#include <ctime>
#include "Word.h"

Word::Word(std::string w): word(w) {
	srand(time(NULL));
}

Word Word::getRandWordFollowing() const{
	int randomIndex = rand() % wordsFollowing.size();
	return wordsFollowing[randomIndex];
}

std::vector<Word> Word::getWordsFollowing() const{
	return wordsFollowing;
}

void Word::addWordFollowing(Word wordToAdd) {
	wordsFollowing.push_back(wordToAdd);
}

std::string Word::toString() const {
	std::string rval = "Word Class:\n\tWord = " + word;
	for(int i = 0; i < wordsFollowing.size(); i++) {
		rval += ("\n\t\t" + wordsFollowing[i].getWord);
	}
	return rval;
}