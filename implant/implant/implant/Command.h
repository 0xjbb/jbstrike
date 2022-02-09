#pragma once
#include <string>
#include <vector>

namespace jbstrike {
	class Command
	{
	public:
		virtual ~Command() {
		}
		virtual void Execute(std::vector<std::string> args) const = 0;

	};
}

