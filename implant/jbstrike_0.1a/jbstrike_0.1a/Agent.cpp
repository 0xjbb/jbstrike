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
	
}

std::string Agent::Post(std::string path, std::string data) {
	// path = path + "/" + AgentID + "/"

}

void Agent::shell() {

}