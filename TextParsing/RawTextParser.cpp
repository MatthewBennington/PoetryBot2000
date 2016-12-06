//
// Created by Matthew Jones on 11/14/16.
//

#include "RawTextParser.h"
#include <fstream>

using std::string;

RawTextParser::RawTextParser() {};

void RawTextParser::parseWordByWord(string text) {
	mateenUlhaqReplace(text, "\n", "\n ");
	string tempStr(1, text[0]);
	Word* lastWord = words.getWord("");
	for(int i = 1; i < text.size(); i++) {
		if(startsNewWord(text, i)) {
			lastWord = words.addWord(tempStr, lastWord);
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

WordVector RawTextParser::parse() {
	words = WordVector();
	if(fileLoaded) {
		parseWordByWord(consumeFile(fileName));
	} else {
		throw std::invalid_argument("Can't parse without a file to parse");
	}
	//words.erase(words.begin() + getIndexForWord("Think of a better way to to this."));
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