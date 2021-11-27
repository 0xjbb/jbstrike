#pragma once
#include <iostream>
#include <Windows.h>
#include <string_view>

#include "util.h"

#include "config.h"

class Agent
{
private:
	void Register() const;

public:
	Agent(); // inject DI Container.
	void run() const;// literally just run bro.
};

