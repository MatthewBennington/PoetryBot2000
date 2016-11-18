//
// Created by Matthew Jones on 11/14/16.
//

#ifndef FINAL_WORD_H
#define FINAL_WORD_H


#include <vector>
#include <string>

class Word {
public:
	Word(std::string w);
	Word getRandWordFollowing()const ;
	std::vector<Word> getWordsFollowing()const ;
	void addWordFollowing(Word wordToAdd);
	std::string getWord const;
	std::string toString() const;
private:
	std::vector<Word> wordsFollowing;
	std::string word;
};


#endif //FINAL_WORD_H
