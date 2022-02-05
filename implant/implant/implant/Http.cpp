#include "Http.h"
#pragma comment(lib, "wininet.lib")


std::string jbstrike::Http::Get(std::string uri, std::string path) {
	std::string header = "Accept: *" "/" "*\r\n\r\n";

	int size = 30000000;//@todo fix this.

	HANDLE hInet = InternetOpen("jbstrike", INTERNET_OPEN_TYPE_DIRECT, NULL, NULL, NULL);
	HANDLE hURL = InternetOpenUrl(hInet, uri.c_str(), header.c_str(), header.size(), INTERNET_FLAG_DONT_CACHE, 0);
	
	char* buffer = new char[size];
	memset(buffer, 0, size);
	DWORD rBytes = 1;

	std::string data;

	if (InternetReadFile(hURL, buffer, size, &rBytes)) {
		data = std::string(buffer);
	}

	delete[] buffer;
	InternetCloseHandle(hInet);
	InternetCloseHandle(hURL);

	return data;
}