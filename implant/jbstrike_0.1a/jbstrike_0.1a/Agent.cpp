#include "Agent.h"


void Agent::Register() {
	wchar_t computerName[MAX_COMPUTERNAME_LENGTH + 1];
	DWORD size = sizeof(ComputerName) / sizeof(computerName[0]);

	GetComputerNameW(computerName, &size);
	std::wstring test = string(computerName);

	std::cout<< computerName << std::endl;
}

Agent::Agent(std::string ip, unsigned int port) {
	ipAddress = ip;
	port = port;
	Register();
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


void Agent::shell() {
	
}

void Agent::upload() {

}

void Agent::download() {

}

//void Agent::ListDirectory() {}