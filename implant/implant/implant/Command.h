#pragma once


namespace jbstrike {
	class Command
	{
	public:
		virtual ~Command() {
		}
		virtual void Execute(std::vector<std::string> args) const = 0;

	};
}

