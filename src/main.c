#include <windows.h>

#include "window.h"

int WINAPI WinMain(HINSTANCE instanceHandle, HINSTANCE previousHandle,
	PSTR commandArguments, int showState) {

	SetMainWindow("Physio", 1024, 768, showState);

	return 0;
}
