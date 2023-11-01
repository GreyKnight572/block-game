#ifdef _WIN32

#include <windows.h>

#endif

#include "window.h"

#ifdef _WIN32

int WINAPI WinMain(HINSTANCE instanceHandle, HINSTANCE previousHandle,
	PSTR commandArguments, int showState) {

	InitializeMainWindow("Physio", 1024, 768, showState);

	return 0;
}

#endif
