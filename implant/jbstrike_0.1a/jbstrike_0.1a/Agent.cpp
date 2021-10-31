#include "Agent.h"

class Agent {

private:
	// command handler.
	std::string HandlerURI;
	std::string ComputerName;
	std::string AgentID; // MD5 of computername or something
	std::string ipAddress;
	unsigned int port;

public:
	// ip/port for c2server
	Agent(std::string ip, unsigned int port) {
		ipAddress = ip;
		port = port;
	}


	std::string Get(std::string path) {
		// path = path + "/" + AgentID + "/"
	
	}

	void Register() {
		//GetComputerNameW();

	
	}


};