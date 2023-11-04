#include <windows.h>

LRESULT CALLBACK WindowProcedure(HWND windowHandle, UINT message,
	WPARAM wordParameter, LPARAM longParameter);

int WINAPI WinMain(HINSTANCE instanceHandle, HINSTANCE previousHandle,
	PSTR commandArguments, int showCommand) {

	LPCSTR windowName;
	int windowWidth, windowHeight;
	int screenWidth, screenHeight;
	int windowPositionX, windowPositionY;
	WNDCLASSA windowClass;
	HWND windowHandle;
	MSG message;

	windowName = "Physio";
	windowWidth = 1024;
	windowHeight = 768;

	screenWidth = GetSystemMetrics(SM_CXSCREEN);
	screenHeight = GetSystemMetrics(SM_CYSCREEN);
	windowPositionX = (screenWidth - windowWidth) / 2;
	windowPositionY = (screenHeight - windowHeight) / 2;

	windowClass.cbClsExtra = FALSE;
	windowClass.cbWndExtra = FALSE;
	windowClass.hbrBackground = NULL;
	windowClass.hCursor = LoadCursorA(NULL, IDC_ARROW);
	windowClass.hIcon = NULL;
	windowClass.hInstance = instanceHandle;
	windowClass.lpfnWndProc = WindowProcedure;
	windowClass.lpszClassName = "Window";
	windowClass.lpszMenuName = NULL;
	windowClass.style = FALSE;
	RegisterClassA(&windowClass);

	windowHandle = CreateWindowExA(FALSE, windowClass.lpszClassName,
		windowName, WS_OVERLAPPEDWINDOW,
		windowPositionX, windowPositionY, windowWidth, windowHeight,
		NULL, NULL, instanceHandle, NULL);
	ShowWindow(windowHandle, showCommand);

	while (GetMessageA(&message, NULL, FALSE, FALSE)) {

		DispatchMessageA(&message);
	}

	return (int) message.wParam;
}

LRESULT CALLBACK WindowProcedure(HWND windowHandle, UINT message,
	WPARAM wordParameter, LPARAM longParameter) {

	switch (message) {

		case WM_DESTROY:
		PostQuitMessage(0);
	}

	return DefWindowProcA(windowHandle, message, wordParameter, longParameter);
}
