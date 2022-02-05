#pragma once
#include <string>
#include <Windows.h>
#include <wininet.h>

namespace jbstrike {
	class Http
	{
	public:
		std::string Get(std::string uri, std::string path);
		std::string Post(std::string uri, std::string path);
	};
}
