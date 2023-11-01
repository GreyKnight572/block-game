#include <windows.h>

LRESULT CALLBACK WindowProcedure(HWND windowHandle, UINT message,
	WPARAM wordParameter, LPARAM longParameter);

int WINAPI WinMain(HINSTANCE instanceHandle, HINSTANCE previousHandle,
	PSTR commandArguments, int showState) {

		LPCSTR windowTitle;
		int windowWidth, windowHeight;
		int screenWidth, screenHeight;
		int windowPositionX, windowPositionY;
		WNDCLASSA windowClass = {0};
		HWND windowHandle;
		MSG message;

		windowTitle = "Physio";
		windowWidth = 1024;
		windowHeight = 768;

		screenWidth = GetSystemMetrics(SM_CXSCREEN);
		screenHeight = GetSystemMetrics(SM_CYSCREEN);
		windowPositionX = (screenWidth - windowWidth) / 2;
		windowPositionY = (screenHeight - windowHeight) / 2;

		windowClass.hCursor = LoadCursorA(NULL, IDC_ARROW);
		windowClass.hInstance = instanceHandle;
		windowClass.lpfnWndProc = WindowProcedure;
		windowClass.lpszClassName = "Window";
		RegisterClassA(&windowClass);

		windowHandle = CreateWindowExA(FALSE, windowClass.lpszClassName,
			windowTitle, WS_OVERLAPPEDWINDOW,
			windowPositionX, windowPositionY, windowWidth, windowHeight,
			NULL, NULL, instanceHandle, NULL);
		ShowWindow(windowHandle, showState);

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
		break;
	}

	return DefWindowProcA(windowHandle, message, wordParameter, longParameter);
}
