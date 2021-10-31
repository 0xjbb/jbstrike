#pragma once
#include <functional>
#include <iostream>
#include <vector>
#include <string>
#include <map>


class Command
{
	std::map<std::string, std::function<void()>> Commands;
public:
	bool HasCommand(std::string command);
	void RegisterCommand(std::string name, std::function<void()> func);
	void ExecuteCommand(std::string name);
};

