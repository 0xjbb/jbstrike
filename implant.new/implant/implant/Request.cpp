#include "Request.h"
#include "Config.h"

bool Request::_validURI() {
	if (Uri == L"") {
		return false;
	}
	return true;
}

bool Request::_rawRequest() {
	// Use WinHttpOpen to obtain a session handle.
	LPSTR data = const_cast<char*>(PostData.c_str());
	DWORD data_len = strlen(data);

	LPCWSTR headers = L"Content-Type: application/x-www-form-urlencoded\r\n";
	DWORD headersLength = -1;

	if (Verb == L"GET") {
		LPSTR data = WINHTTP_NO_REQUEST_DATA;
		DWORD data_len = 0;
		LPCWSTR headers = WINHTTP_NO_ADDITIONAL_HEADERS;
		DWORD headersLength = 0;
	}

	hSession = WinHttpOpen(Agent.c_str(),
		WINHTTP_ACCESS_TYPE_DEFAULT_PROXY,
		WINHTTP_NO_PROXY_NAME,
		WINHTTP_NO_PROXY_BYPASS, 0);

	// Specify an HTTP server.
	if (hSession)
		hConnect = WinHttpConnect(hSession, Uri.c_str(),
			Port, 0);

	// Create an HTTP request handle.
	if (hConnect)
		hRequest = WinHttpOpenRequest(hConnect, Verb.c_str(), Path.c_str(),
			nullptr, WINHTTP_NO_REFERER,
			WINHTTP_DEFAULT_ACCEPT_TYPES,
			WINHTTP_FLAG_SECURE);

	// Send a request.
	if (hRequest) {
		bResults = WinHttpSendRequest(hRequest,
			headers,
			headersLength,
			(LPVOID)data,
			data_len,
			data_len,
			0);
	}
	// End the request.
	if (bResults)
		bResults = WinHttpReceiveResponse(hRequest, nullptr);

	// Keep checking for data until there is nothing left.
	if (bResults)
		do
		{
			// Check for available data.
			dwSize = 0;
			if (!WinHttpQueryDataAvailable(hRequest, &dwSize)) return false;

			// Allocate space for the buffer.
			pszOutBuffer = new char[dwSize + 1];
			if (!pszOutBuffer)
			{
				dwSize = 0;
				return false;
			}
			// Read the Data.
			ZeroMemory(pszOutBuffer, dwSize + 1);

			if (!WinHttpReadData(hRequest, (LPVOID)pszOutBuffer,
				dwSize, &dwDownloaded)) {
				return false;
			}
			else {
				Result = Result + std::string(pszOutBuffer);
				return true;
			}

			// Free the memory allocated to the buffer.
			delete[] pszOutBuffer;
		} while (dwSize > 0);

		// Close any open handles.
		if (hRequest) WinHttpCloseHandle(hRequest);
		if (hConnect) WinHttpCloseHandle(hConnect);
		if (hSession) WinHttpCloseHandle(hSession);

		// Report any errors.
		if (!bResults) {
			return false;
		}

		return false;
}

/*
	Set the initual URL
*/
Request::Request(std::wstring_view uri, unsigned short port, std::wstring_view agent) : Uri{ uri }, Port{ port }, Agent{ agent }{}

std::string Request::Get(std::wstring_view uri) {
	Verb = L"GET";
	Path = uri;
	if (_rawRequest()) {
		return Result;
	}
	return "";//send error?
}

std::string Request::Post(std::wstring_view uri, std::wstring_view data) {
	Verb = L"POST";
	Path = uri;
	if (_rawRequest()) {
		return Result;
	}
	return "";//send error?
}