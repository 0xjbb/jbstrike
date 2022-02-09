#pragma once
#include <windows.h>
#include "Command.h"
#include "Invoker.h"
#include "Config.h"
#include "Http.h"
#include "TypeDefs.h"


namespace jbstrike {
	class Exit : public Command {

	private:

	public:
		void Execute(std::vector<std::string> args) const override;
	};
}

