#include <iostream>
#include "ArgumentParsing/Options.h"
#include <string>

/*
 * Notes:
 * When messing around with argv, [0] is the path of the executable, [1] is the first arg, [2] is blank
 * TODO Add option to export to file
 */

void printHelpMsg() {
	const std::string helpMsg =
			"You are seeing this message because you either entered the \"-h\" flag, or entered incorrect flags. \n"
			"Poetry Bot 2000 generated text based on text it is given. \n"
			"-h, --help Display this message \n"
			"-r, -rawText <filename> Run using text from file \n"
			"-p, --parsedText <filename> Run using text imported earlier \n"
			"-f, --exportToFile <filename> Export raw text to parsed text file instead of making poetry\n";
	std::cout << helpMsg << std::endl;
}

int main(int argc, char **argv) {
	const Options options(argc, argv);
	if(options.needsHelp()) {
		printHelpMsg();
		return 0;
	} else if (options.useParsedText() && options.exportToFile()) {
		std::cout << "Can't translate already parsed text." << std::endl;
		return 1;
	}
    return 0;
}