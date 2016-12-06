//
// Created by Matthew Jones on 11/28/16.
//

#include <cstdlib>
#include "WordVector.h"

WordVector::WordVector() {
	Word* word = new Word("");
	words.push_back(word);
}

bool WordVector::containsStr(std::string str) const {
	for(int i = 0; i < words.size(); i++) {
		if(words[i]->getWord() == str) {
			return true;
		}
	}
	return false;
}

Word *WordVector::addWord(std::string word, Word *lastWord) {
	if(containsStr(word)) {
		lastWord->addWordFollowing(getWord(word));
		return getWord(word);
	} else {
		Word* temp = new Word(word);
		addToV(temp);
		lastWord->addWordFollowing(temp);
		return temp;
	}
}

Word *WordVector::getWord(std::string str) const {
	return words[getIndexForWord(str)];
}

Word *WordVector::getRandWord() const {
	srand(time(NULL));
	int randomIndex = rand() % words.size();
	return words[randomIndex];
}

int WordVector::getIndexForWord(std::string str, int begin, int end) const { //FIXME Will hang if word is not in array
	if(end == 0)
		end = words.size(); //FIXME Ugly, and terrible.
	int mid = (begin + end) / 2;
	if(words[mid]->getWord() == str) {
		return mid;
	} else if(words[mid]->getWord() > str) {
		return getIndexForWord(str, begin, mid);
	} else {
		return getIndexForWord(str, mid, end);
	}
}

void WordVector::addToV(Word *word) {
	for(int i = 0; i < words.size(); i++) {
		if(words[i]->getWord() > word->getWord()) {
			words.insert(words.begin() + i, word);
			return;
		}
	}
	words.push_back(word);
}

std::vector<Word *> WordVector::dumpWords() const {
	return words;
}

void WordVector::addWord(std::string word, std::vector<std::string> words) {
	Word* wordPtr;
	bool alreadyThere;
	if(containsStr(word)) {
		wordPtr = getWord(word);
		alreadyThere = true;
	} else {
		wordPtr = new Word(word);
		alreadyThere = false;
	}
	for(int i = 0; i < words.size(); i++) {
		Word* anotherWordPtr;
		if(containsStr(words[i])) {
			anotherWordPtr = getWord(words[i]);
		} else {
			anotherWordPtr = new Word(words[i]);
		}
		wordPtr->addWordFollowing(anotherWordPtr);
		addToV(anotherWordPtr);
	}
	if(!alreadyThere) {
		addToV(wordPtr);
	}
}
