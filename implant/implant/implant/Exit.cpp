#include "Exit.h"


void jbstrike::Exit::Execute(std::vector<std::string> args) const {
	ExitProcess(1);
}