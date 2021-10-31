#include "Command.h"
#include "Agent.h"

bool Command::HasCommand(std::string command) {
	if (Commands.contains(command)) {
		return true;
	}

	return false;
}

void Command::RegisterCommand(std::string name, Agent function) {
	Commands[name] = function;
}

	// reflection
bool Command::ExecuteCommand(std::string name) {
	
}

