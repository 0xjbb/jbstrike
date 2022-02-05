#include "Util.h"

std::string jbstrike::GenerateUniqueId() {
	HW_PROFILE_INFO   profile;

	if (!GetCurrentHwProfile(&profile)) {
		return "Unknown";
	}

	return std::string(profile.szHwProfileGuid);
}


std::vector <std::string> jbstrike::split(std::string cmd, char delimiter) {
	std::string line;
	std::vector <std::string> vec;
	std::stringstream ss(cmd);

	while (std::getline(ss, line, delimiter)) {
		vec.push_back(line);
	}
	return vec;
}
