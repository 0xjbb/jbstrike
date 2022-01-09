#pragma once
#include <functional>
#include <iostream>
#include <vector>
#include <string>
#include <map>


class Command
{
private:
	std::map<std::string, std::function<void(std::vector<std::string>)>> Commands;




public:
	bool HasCommand(std::string command);
	void RegisterCommand(std::string name, std::function<void(std::vector<std::string>)> func);//why warning fml
	void ExecuteCommand(std::string name, std::vector<std::string> args);
};

