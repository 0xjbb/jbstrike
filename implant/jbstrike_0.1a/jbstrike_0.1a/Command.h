#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <map>

typedef void (*FnPtr)();

class Command
{
	std::map<std::string, FnPtr> Commands;
public:
	bool HasCommand(std::string command);
	void RegisterCommand(std::string name, FnPtr func);
	bool ExecuteCommand(std::string name);
};

