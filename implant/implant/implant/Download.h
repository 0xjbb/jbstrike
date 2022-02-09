#pragma once
#include <windows.h>
#include "Command.h"
#include "Invoker.h"
#include "Config.h"
#include "Http.h"
#include "TypeDefs.h"


namespace jbstrike {
	class Downloader : public Command {

	private:
		Http* http;

	public:
		Downloader(Http* http) : http(http) {}
		void Execute(std::vector<std::string> args) const override;
	};
}