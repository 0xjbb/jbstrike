#pragma once
#include <windows.h>
#include "Command.h"
#include "Invoker.h"
#include "Config.h"
#include "Http.h"
#include "TypeDefs.h"
#include "util.h"

namespace jbstrike {

	struct ReceivedCmd {
		std::string Command;
		std::vector<std::string> Args;
	};

	class Application
	{
	private:
		Invoker Commands;
		Config cfg;
		Http http;
	public:
		Application();
		void Run();
		ReceivedCmd ParseData(std::string data);

	};

}