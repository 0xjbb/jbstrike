#pragma once


namespace jbstrike {
	class Command
	{
	public:
		virtual ~Command() {
		}
		virtual void Execute() const = 0;

	};
}

