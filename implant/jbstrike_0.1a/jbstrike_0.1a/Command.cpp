#include "Command.h"


class Command
{
	std::map<std::string, std::string> Commands;
public:
	bool HasCommand(std::string command) {
		if (Commands.contains(command)) {
			return true;
		}

		return false;
	}

	void RegisterCommand(std::string name, std::string function) {
		Commands[name] = function;
	}

	// reflection
	bool ExecuteCommand(std::string name) {
	
	}
};

