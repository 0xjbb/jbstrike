#include "Invoker.h"

// execute command
void jbstrike::Invoker::Run(std::string name, std::vector<std::string> args) {
	if (this->commands.find(name) != this->commands.end()) {
		this->commands.at(name)->Execute(args);
	}
}

// set command
void jbstrike::Invoker::Set(std::string name, Command *cmd) {
	this->commands.at(name) = cmd;
}

// check if we have it.
bool jbstrike::Invoker::Has(std::string name) {
	if (this->commands.find(name) != this->commands.end()) {
		return true;
	}

	return false;
}