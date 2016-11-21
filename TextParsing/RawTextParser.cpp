//
// Created by Matthew Jones on 11/14/16.
//

#include "RawTextParser.h"
#include <fstream>
#include <regex>

using std::string;

RawTextParser::RawTextParser() {};

string RawTextParser::consumeFile(string fileName) {
	string rval;
	string line;
	std::ifstream fileToParse(fileName);
	if(fileToParse.is_open()) {
		while(getline(fileToParse, line)) {
			rval += (line + "\n");
		}
		fileToParse.close();
	} else {
		throw std::invalid_argument("could not open file: " + fileName);
	}
	return rval;
}

void RawTextParser::parseWordByWord(string text) {
	mateenUlhaqReplace(text, "\n", "\n ");
	string tempStr(1, text[0]);
	Word* lastWord = new Word("Think of a better way to to this."); //FIXME
	words.push_back(lastWord);
	for(int i = 1; i < text.size(); i++) {
		if(startsNewWord(text, i)) {
			lastWord = addWord(tempStr, lastWord);
			tempStr = "";
		}
		tempStr += text[i];
	}
}

/// @author mateen-ulhaq
std::string RawTextParser::mateenUlhaqReplace(std::string &s,
					  const std::string &toReplace,
					  const std::string &replaceWith)
{
	return(s.replace(s.find(toReplace), toReplace.length(), replaceWith));
}

std::vector<Word*> RawTextParser::parse() {
	words = std::vector<Word*>();
	if(fileLoaded) {
		parseWordByWord(consumeFile(fileName));
	} else {
		throw std::invalid_argument("Can't parse without a file to parse");
	}
	words.erase(words.begin() + getIndexForWord("Think of a better way to to this."));
	return words;
}

bool RawTextParser::startsNewWord(string text, int &index) {
	switch(text[index]) {//TODO Will need tuning
		case '.':
			return true;
		case ',':
			return true;
		case '?':
			return true;
		case '!':
			return true;
		case ':':
			return true;
		case ';':
			return true;
		case '\n':
			return true;
		case '\"':
			index++;
			return true;
		case ' ':
			index++;
			return true;
		default:
			return false;
	}
}

bool RawTextParser::containsStr(string str) const {
	for(int i = 0; i < words.size(); i++) {
		if(words[i]->getWord() == str) {
			return true;
		}
	}
	return false;
}

Word* RawTextParser::getWord(string str) const {
	return words[getIndexForWord(str)];
}

void RawTextParser::addToV(Word *word) {
	for(int i = 0; i < words.size(); i++) {
		if(words[i]->getWord() > word->getWord()) {
			words.insert(words.begin() + i, word);
			return;
		}
	}
	words.push_back(word);
}

Word* RawTextParser::addWord(std::string word, Word* lastWord) {
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

int RawTextParser::getIndexForWord(std::string str, int begin, int end) const { //FIXME Will hang if word is not in array
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
