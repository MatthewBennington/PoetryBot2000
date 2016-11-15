//
// Created by Matthew Jones on 11/14/16.
//

#ifndef FINAL_WORD_H
#define FINAL_WORD_H


#include <vector>
#include <string>

//TODO ask juston how to make each word unique, vectors a reference

class Word {
public:
	Word(std::string w);
	Word getRandWordFollowing();
	std::vector<Word> getWordsFollowing();
	void addWordFollowing(Word wordToAdd);
	std::string getWord;
private:
	std::vector<Word> wordsFollowing;
	std::string word;
};


#endif //FINAL_WORD_H
