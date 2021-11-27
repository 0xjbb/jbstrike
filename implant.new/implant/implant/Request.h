#pragma once
#include <iostream>
#include <Windows.h>
#include <winhttp.h>
#include <string_view>
#pragma comment(lib, "winhttp.lib")

class Request
{
private:
	std::wstring Uri = L""; // http://example.com
	std::wstring Verb = L"GET";
	unsigned short Port;
	std::wstring Agent = L"";
	std::string Result = "";
	std::string PostData = "";
	std::wstring Path = L"/";

	HINTERNET hSession = nullptr;
	HINTERNET hConnect = nullptr;
	HINTERNET hRequest = nullptr;
	bool bResults = false;
	DWORD dwSize = 0;
	DWORD dwDownloaded = 0;
	LPSTR pszOutBuffer;

	bool _validURI();
	bool _rawRequest();
public:
	Request(std::wstring_view uri, unsigned short port, std::wstring_view agent);

	std::string Get(std::wstring_view uri);
	std::string Post(std::wstring_view uri, std::wstring_view data);
};
