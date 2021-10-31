#include "Command.h"
#include "Agent.h"

bool Command::HasCommand(std::string command) {
	if (Commands.contains(command)) {
		return true;
	}

	return false;
}

void Command::RegisterCommand(std::string name, std::function<void()> func) {
	if (!HasCommand(name)) {
		Commands[name] = func;
	}
}

	// reflection
bool Command::ExecuteCommand(std::string name) {
	if (!HasCommand(name)) {
		Commands[name]();
	}
}

