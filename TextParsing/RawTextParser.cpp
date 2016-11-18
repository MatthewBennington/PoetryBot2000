//
// Created by Matthew Jones on 11/14/16.
//

#include "RawTextParser.h"
#include <fstream>
#include <regex>

using std::string;

RawTextParser::RawTextParser(string file) {
	text = consumeFile(file);
}

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
	string tempStr = "" + text[0]; //FIXME It complains if I just assign it to a char, but this is damn ugly.
	Word lastWord = NULL;
	for(int i = 1; i < text.size(); i++) {
		if(startsNewWord(text, i)) {
			addWord(tempStr, lastWord);
			tempStr = "";
		}
		tempStr += text[i];
	}
}

std::vector<Word> RawTextParser::parse() {
	parseWordByWord(text);
	return words;
}

bool RawTextParser::startsNewWord(string text, int &index) {
	switch(text[index]) {//TODO Will need tuning
		case '.':
			return true;
		case ',':
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
		if(words[i].getWord == str) {
			return true;
		}
	}
	return false;
}

Word RawTextParser::getWord(string str) const {
	return words[getIndexForWord(str)];
}

void RawTextParser::addToV(Word word) {
	for(int i = 0; i < words.size(); i++) {
		if(words[i].getWord > word.getWord) {
			words.insert(words.begin() + i, word);
			return;
		}
	}
	words.push_back(word);
}

void RawTextParser::addWord(std::string word, Word lastWord) {
	if(containsStr(word)) {
		lastWord.addWordFollowing(getWord(word));
	} else {
		Word temp(word);
		addToV(temp);
		lastWord.addWordFollowing(temp);
	}
}

int RawTextParser::getIndexForWord(std::string str, int begin = 0, int end = words.size()) const { //FIXME Will hang if word is not in array
	int mid = (begin + end) / 2;
	if(words[mid].getWord == str) {
		return mid;
	} else if(words[mid].getWord > str) {
		return getIndexForWord(str, begin, mid);
	} else {
		return getIndexForWord(str, mid, end);
	}
}
