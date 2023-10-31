#include "windows-base.h"

int WinMain(void* instanceHandle, void* previousHandle,
	char* commandArguments, int showState) {

	void* windowHandle = 0;

	windowHandle = CreateMainWindow(instanceHandle, 1024, 768, "Physio");
	SetShowState(windowHandle, showState);

	return MessageLoopTODO();
}
