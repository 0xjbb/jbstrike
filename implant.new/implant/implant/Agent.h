#pragma once
#include <iostream>
#include <Windows.h>
#include <string_view>

#include "util.h"
#include "config.h"
#include "Request.h"
#include "Command.h"

class Agent
{
private:
	Request hRequest;
	Command hCommand;


	void Register();

public:
	Agent(Request req, Command cmd); // inject DI Container.
	void run();// literally just run bro.
};

