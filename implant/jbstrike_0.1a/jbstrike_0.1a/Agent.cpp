#include "Agent.h"


void Agent::Register() {
	//GetComputerNameW();


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
	std::cout << "Shell function called" << std::endl;
}

void Agent::upload() {

}

void Agent::download() {

}