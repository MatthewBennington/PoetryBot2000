// http://stackoverflow.com/a/868894/5843840

#ifndef FINAL_ARGPARSER_H
#define FINAL_ARGPARSER_H


#include <string>
#include <vector>

class ArgParser {
public:
	ArgParser (int &argc, char **argv);
	/// @author iain
	const std::string& getCmdOption(const std::string &option) const;
	/// @author iain
	bool cmdOptionExists(const std::string &option) const;
	bool existsOR(const std::string option1, std::string option2) const;
private:
	std::vector <std::string> tokens;
};


#endif //FINAL_ARGPARSER_H
