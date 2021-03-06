#pragma once
#include <map>
#include <string>

#include "Command.h"

namespace jbstrike {
	class Invoker
	{
	private:
		std::map<std::string, Command*> commands;


	public:
		void Run(std::string name, std::vector<std::string> args);
		void Set(std::string name, Command *cmd);
		bool Has(std::string name);
	};
};
