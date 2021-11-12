#pragma once
#include <iostream>
#include <winhttp.h>
#include <windows.h>


class Http
{
	std::wstring Host;
	INTERNET_PORT Port;
	HANDLE hSession, hConnect, hRequest;
	BOOL bResults;

public:
	Http(std::wstring host, INTERNET_PORT port);
	std::string Get();
	std::string Post();
};

