#include <iostream>
#include <vector>
#include "ArgumentParsing/Options.h"
#include "TextParsing/RawTextParser.h"
#include "PrettyPrinter.h"
#include "FilePrinter.h"
#include "TextParsing/ParsedTextParser.h"
#include <string>

/*
 * Notes:
 * When messing around with argv, [0] is the path of the executable, [1] is the first arg, [2] is blank
 * TODO Maybe seperate words into its own class
 */

void printHelpMsg() {
	const std::string helpMsg =
			"You are seeing this message because you either entered the \"-h\" flag, or entered incorrect flags. \n"
			"Poetry Bot 2000 generates text based on text it is given. \n"
			"-h, --help Display this message \n"
			"-r, -rawText <filename> Run using text from file \n"
			"-p, --parsedText <filename> Run using text imported earlier \n"
			"-f, --exportToFile <filename> Export raw text to parsed text file instead of making poetry\n"
			"-d, --debug Print the corpus as JSON\n";
	std::cout << helpMsg << std::endl;
}

std::string printDebugMessage(WordVector words) {
	std::string rval;
	std::vector<Word*> wordsV = words.dumpWords();
	for(int i = 0; i < wordsV.size(); i++) {
		rval += wordsV[i]->toString() + "\n";
	}
	return rval;
}

int main(int argc, char **argv) {
	const Options options(argc, argv);
	WordVector words;
	if(options.needsHelp()) {
		printHelpMsg();
		return 0;
	} else if (options.useParsedText() && options.exportToFile()) {
		std::cout << "Can't translate already parsed text." << std::endl;
		return 1;
	} else if(options.useRawText()) {
		std::string file = options.getFileName();
		RawTextParser parser;
		parser.loadFile(file);
		words = parser.parse();
	} else if(options.useParsedText()) {
		std::string file = options.getFileName();
		ParsedTextParser parser;
		parser.loadFile(file);
		words = parser.parse();
	}

	if(options.debug()) {
		printDebugMessage(words);
	}
	if(options.exportToFile()) {
		FilePrinter printer(words);
		printer.print(options.exportFileName());
	}
	PrettyPrinter printer(words);
	std::cout << printer.print() << std::endl;
    return 0;
}