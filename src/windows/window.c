#include "window.h"
#include "message.h"

HINSTANCE instanceHandle = NULL;
HWND mainWindowHandle = NULL;

void SetMainWindow(LPCSTR windowTitle,
	int windowWidth, int windowHeight, int showState) {

	int screenWidth, screenHeight, windowPositionX, windowPositionY;
	WNDCLASSA windowClass = {0};

	if (!instanceHandle) {

		GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT,
			NULL, instanceHandle);
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
	}

	SetWindowPos(mainWindowHandle, HWND_TOP,
		windowPositionX, windowPositionY, windowWidth, windowHeight,
		FALSE);
	ShowWindow(mainWindowHandle, showState);
}
