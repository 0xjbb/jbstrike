#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <windows.h>

namespace jbstrike {
	std::string GenerateUniqueId();
	std::vector <std::string> split(std::string cmd, char delimiter = '|');
}