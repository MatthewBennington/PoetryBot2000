//
// Created by Matthew Jones on 11/14/16.
//

#ifndef FINAL_OPTIONS_H
#define FINAL_OPTIONS_H

#include <string>

/*
 * Options we need:
 * 	Whether we are parsing a file from scratch, or importing already parsed words
 * 	flag for the file to be read
 */

class Options {
public:
	Options(int &argc, char **argv);
	bool needsHelp() const;
	bool useRawText() const;
	bool useParsedText() const;
	bool exportToFile() const;
	std::string exportFileName() const;
	bool debug() const;
	std::string getFileName() const;
private:
	bool help;
	bool _useRawText = false;
	bool _useParsedText = false;
	bool _exportToFile = false;
	std::string _exportFileName;
	bool _debug = false;
	std::string fileName;
};


#endif //FINAL_OPTIONS_H
