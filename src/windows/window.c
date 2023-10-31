#include <windows.h>

#include "window.h"
#include "message.h"

void* CreateMainWindow(void* instanceHandle, int windowWidth, int windowHeight,
	char* windowTitle) {

	int screenWidth, screenHeight, windowPositionX, windowPositionY;
	WNDCLASSA windowClass = {0};
	void* windowhandle = 0;

	screenWidth = GetSystemMetrics(SM_CXSCREEN);
	screenHeight = GetSystemMetrics(SM_CYSCREEN);
	windowPositionX = (screenWidth - windowWidth) / 2;
	windowPositionY = (screenHeight - windowHeight) / 2;

	windowClass.lpszClassName = "MainWindow";
	windowClass.hInstance = instanceHandle;
	windowClass.lpfnWndProc = HandleMessage;
	windowClass.hCursor = LoadCursorA(NULL, IDC_ARROW);

	RegisterClassA(&windowClass);
	windowhandle = CreateWindowExA(0, windowClass.lpszClassName, windowTitle,
		WS_OVERLAPPEDWINDOW,
		windowPositionX, windowPositionY, windowWidth, windowHeight,
		0, 0, instanceHandle, 0);

	return windowhandle;
}

void SetShowState(void* windowHandle, int showState) {

	ShowWindow(windowHandle, showState);
}
