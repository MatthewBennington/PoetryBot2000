//
// Created by Matthew Jones on 11/14/16.
//

#include "Options.h"
#include "ArgParser.h"

Options::Options(int &argc, char **argv) {
	ArgParser args(argc, argv);
	help = (args.cmdOptionExists("-h") || args.cmdOptionExists("--help"));
	_debug = args.cmdOptionExists("-d") || args.cmdOptionExists("--debug");
	if(args.cmdOptionExists("-f")) {
		_exportToFile = true;
		_exportFileName = args.getCmdOption("-f");
	} else if(args.cmdOptionExists("--exportToFile")) {
		_exportToFile = true;
		_exportFileName = args.getCmdOption("--exportToFile");
	}
	if (args.cmdOptionExists("-r")) {
		_useRawText = true;
		_useParsedText = false;
		fileName = args.getCmdOption("-r");
	} else if (args.cmdOptionExists("--rawText")) {
		_useRawText = true;
		_useParsedText = false;
		fileName = args.getCmdOption("--rawText");
	} else if (args.cmdOptionExists("-p")) {
		_useRawText = false;
		_useParsedText = true;
		fileName = args.getCmdOption("-p");
	} else if (args.cmdOptionExists("--parsedText")) {
		_useRawText = false;
		_useParsedText = true;
		fileName = args.getCmdOption("--parsedText");
	} else {
		help = true;
	}
}

bool Options::needsHelp() const {
	return help;
}

bool Options::useRawText() const {
	return _useRawText;
}

bool Options::useParsedText() const {
	return _useParsedText;
}

std::string Options::getFileName() const {
	return fileName;
}

bool Options::exportToFile() const {
	return _exportToFile;
}

bool Options::debug() const {
	return _debug;
}

std::string Options::exportFileName() const {
	return _exportFileName;
}
