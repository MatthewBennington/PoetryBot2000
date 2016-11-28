//
// Created by Matthew Jones on 11/28/16.
//

#ifndef FINAL_WORDVECTOR_H
#define FINAL_WORDVECTOR_H


#include <string>
#include "Word.h"

class WordVector {
public:
	WordVector();
	std::vector<Word*> dumpWords() const;
	bool containsStr(std::string str) const;
	Word* addWord(std::string word, Word* lastWord);
	Word* getWord( std::string str) const;
	Word* getRandWord() const;
private:
	std::vector<Word*> words;
	int getIndexForWord(std::string str, int begin = 0, int end = 0) const;
	void addToV(Word* word);
};


#endif //FINAL_WORDVECTOR_H
