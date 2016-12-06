//
// Created by Matthew Jones on 11/28/16.
//

#include "ParsedTextParser.h"
#include "../lib/json.hpp"

using std::string;
using json = nlohmann::json;

ParsedTextParser::ParsedTextParser() {}

WordVector ParsedTextParser::parse() {
	words = WordVector();
	if(fileLoaded) {
		parseJSON(consumeFile(fileName));
	} else {
		throw std::invalid_argument("Can't parse without a file to parse");
	}
	return words;
}

json ParsedTextParser::stringToJson(std::string str) {
	json rval = json::parse(str);
	return rval;
}

void ParsedTextParser::parseJSON(std::string text) {
	json corpus = stringToJson(text);
	for(json::iterator it = corpus.begin(); it != corpus.end(); ++it) {
		json obj = *it;
		string str = obj["String"];
		std::vector<std::string> wordsFollowing;
		for(auto& element : obj["Words Following"]) {
			wordsFollowing.push_back(element);
		}
		words.addWord(str, wordsFollowing);
	}
}

