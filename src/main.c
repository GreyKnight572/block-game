#include "window.h"

#ifdef _WIN32

#include <windows.h>

int WINAPI WinMain(HINSTANCE instanceHandle, HINSTANCE previousHandle,
	PSTR commandArguments, int showState) {

	InitializeMainWindow("Physio", 1024, 768, showState);

	while (MessageLoopActive()) {}

	return 0;
}

#endif
