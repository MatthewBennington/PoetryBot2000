/// @author iain
// http://stackoverflow.com/a/868894/5843840
#include "ArgParser.h"
/// @author iain
ArgParser::ArgParser(int &argc, char **argv) {
    for (int i=1; i < argc; ++i)
        this->tokens.push_back(std::string(argv[i]));
}
/// @author iain
const std::string &ArgParser::getCmdOption(const std::string &option) const {
    std::vector<std::string>::const_iterator itr;
    itr =  std::find(this->tokens.begin(), this->tokens.end(), option);
    if (itr != this->tokens.end() && ++itr != this->tokens.end()){
        return *itr;
    }
    return "";
}
/// @author iain
bool ArgParser::cmdOptionExists(const std::string &option) const {
	return std::find(this->tokens.begin(), this->tokens.end(), option)
		   != this->tokens.end();
}

//bool ArgParser::existsOR(const std::string option1, std::string option2) const {
//	return (cmdOptionExists(option1) || cmdOptionExists(option2));
//}
