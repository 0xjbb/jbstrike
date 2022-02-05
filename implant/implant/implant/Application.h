#pragma once
#include <windows.h>
#include "Command.h"
#include "Invoker.h"
#include "Config.h"
#include "Http.h"
#include "TypeDefs.h"




namespace jbstrike {

	class Application
	{
	private:
		Invoker Commands;
		Config cfg;
		Http http;
	public:
		Application();
		void Run();

	};

}