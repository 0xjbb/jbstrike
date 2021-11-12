#include "Util.h"


std::vector <std::string> split(std::string cmd, char delimiter) {
	std::string line;
	std::vector <std::string> vec;
	std::stringstream ss(cmd);

	while (std::getline(ss, line, delimiter)) {
		vec.push_back(line);
	}
	return vec;
}

std::string base64_encode(std::string_view data) {
	return "";
}


std::string base64_decode(std::string_view data) {
	return "";
}