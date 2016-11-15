//
// Created by Matthew Jones on 11/14/16.
//

#include <cstdlib>
#include <ctime>
#include "Word.h"

Word::Word(std::string w): word(w) {
	srand(time(NULL));
}

Word Word::getRandWordFollowing() {
	int randomIndex = rand() % wordsFollowing.size();
	return wordsFollowing[randomIndex];
}

std::vector<Word> Word::getWordsFollowing() {
	return wordsFollowing;
}

void Word::addWordFollowing(Word wordToAdd) {
	wordsFollowing.push_back(wordToAdd);
}
