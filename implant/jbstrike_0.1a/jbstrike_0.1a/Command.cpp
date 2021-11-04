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
		Commands.insert(std::pair<std::string, std::function<void()>>(name, func));
	}
}

	// reflection
void Command::ExecuteCommand(std::string name) {
	if (HasCommand(name)) {
		Commands.at(name)();
	}
}

