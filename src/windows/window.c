#include <windows.h>
#include <process.h>

#include "window.h"

HINSTANCE instanceHandle = NULL;
HWND mainWindowHandle = NULL;
HANDLE messageLoopHandle = NULL;
WPARAM quitMessageCode = 0;

LRESULT CALLBACK MainWindowProcedure(HWND windowHandle, UINT message,
	WPARAM wordParameter, LPARAM longParameter);

void MessageLoop(void);

void SetMainWindow(char* windowTitle,
	int windowWidth, int windowHeight, int showState) {

	int screenWidth, screenHeight, windowPositionX, windowPositionY;
	WNDCLASSA windowClass = {0};

	if (!instanceHandle) {

		GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT,
			NULL, &instanceHandle);
	}

	screenWidth = GetSystemMetrics(SM_CXSCREEN);
	screenHeight = GetSystemMetrics(SM_CYSCREEN);
	windowPositionX = (screenWidth - windowWidth) / 2;
	windowPositionY = (screenHeight - windowHeight) / 2;

	if (!mainWindowHandle) {

		windowClass.lpszClassName = "MainWindow";
		windowClass.hInstance = instanceHandle;
		windowClass.lpfnWndProc = MainWindowProcedure;
		windowClass.hCursor = LoadCursorA(NULL, IDC_ARROW);
		RegisterClassA(&windowClass);

		mainWindowHandle = CreateWindowExA(FALSE, windowClass.lpszClassName,
			windowTitle, WS_OVERLAPPEDWINDOW,
			windowPositionX, windowPositionY, windowWidth, windowHeight,
			NULL, NULL, instanceHandle, NULL);

		messageLoopHandle = (HANDLE) _beginthreadex(NULL, 0,
			(void*) MessageLoop, NULL, FALSE, NULL);
	}

	SetWindowPos(mainWindowHandle, HWND_TOP,
		windowPositionX, windowPositionY, windowWidth, windowHeight,
		FALSE);
	ShowWindow(mainWindowHandle, showState);
}

LRESULT CALLBACK MainWindowProcedure(HWND windowHandle, UINT message,
	WPARAM wordParameter, LPARAM longParameter) {

	switch (message) {

	case WM_DESTROY:
		mainWindowHandle = NULL;
		PostQuitMessage(0);
		break;
	}

	return DefWindowProcA(windowHandle, message, wordParameter, longParameter);
}

void MessageLoop(void) {

	MSG message;

	while (GetMessageA(&message, mainWindowHandle, 0, 0)) {

		DispatchMessageA(&message);
	}

	quitMessageCode = message.wParam;
	CloseHandle(messageLoopHandle);
	messageLoopHandle = NULL;
	_endthreadex(0);
}

int MainWindowOpen(void) {

	if (messageLoopHandle) {

		return 1;
	}

	else {

		return 0;
	}
}
