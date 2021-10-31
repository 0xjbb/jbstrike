#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <map>


class Command
{
	std::map<std::string, std::string> Commands;
public:
	bool HasCommand(std::string command);
	void RegisterCommand(std::string name, Agent function);
	bool ExecuteCommand(std::string name);
};

