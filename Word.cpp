//
// Created by Matthew Jones on 11/14/16.
//

#include <cstdlib>
#include <ctime>
#include "Word.h"

Word::Word(std::string w) {
	if(w.length() > 1) {
		switch (w.at(0)) {
			case '.':
			case ',':
			case '?':
			case '!':
			case ':':
			case ';':
			case '\n':
				w.erase(w.begin());
				break;
			default:
				break;
		}
	}
	word = w;
	srand(time(NULL));
}



Word* Word::getRandWordFollowing() const{
	int randomIndex = rand() % wordsFollowing.size();
	return wordsFollowing[randomIndex];
}

std::vector<Word*> Word::getWordsFollowing() const{
	return wordsFollowing;
}

void Word::addWordFollowing(Word *wordToAdd) {
	wordsFollowing.push_back(wordToAdd);
 }

std::string Word::toString() const {
	std::string rval = "{\"Word\": \"" + word + "\"\n\t\"wordsFollowing\": [";
	for(int i = 0; i < wordsFollowing.size(); i++) {
		rval.append("\n\t\t\"").append(wordsFollowing[i]->getWord()).append("\",");
	}
	rval.pop_back();
	rval.append("\n\t]\n}");
	return rval;
}

std::string Word::getWord() const {
	return word;
}
