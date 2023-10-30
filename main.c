#include <windows.h>

LRESULT CALLBACK WindowProcedure(HWND windowHandle, UINT message,
	WPARAM wordParameter, LPARAM longParameter);

int WINAPI WinMain(HINSTANCE instanceHandle, HINSTANCE previousHandle,
	LPSTR commandArguments, int windowShowState) {

	LPSTR windowTitle = "Physio";
	HICON windowIcon = LoadIcon(NULL, IDI_APPLICATION);
	HICON windowCursor = LoadCursor(NULL, IDC_ARROW);

	int screenWidth = GetSystemMetrics(SM_CXSCREEN);
	int screenHeight = GetSystemMetrics(SM_CYSCREEN);
	int windowWidth = 1024;
	int windowHeight = 768;
	int windowPositionX = (screenWidth - windowWidth) / 2;
	int windowPositionY = (screenHeight - windowHeight) / 2;

	WNDCLASS windowClass;
	HWND windowHandle;
	MSG message;

	windowClass.style		 = FALSE;
	windowClass.cbClsExtra	 = FALSE;
	windowClass.cbWndExtra	 = FALSE;
	windowClass.lpszClassName = "GameWindow";
	windowClass.hInstance	 = instanceHandle;
	windowClass.hbrBackground = NULL;
	windowClass.lpszMenuName	 = NULL;
	windowClass.lpfnWndProc	 = WindowProcedure;
	windowClass.hCursor		 = windowCursor;
	windowClass.hIcon		 = windowIcon;
	RegisterClass(&windowClass);

	windowHandle = CreateWindow(windowClass.lpszClassName, windowTitle,
		WS_OVERLAPPEDWINDOW | WS_VISIBLE,
		windowPositionX, windowPositionY, windowWidth, windowHeight,
		NULL, NULL, instanceHandle, NULL);
	ShowWindow(windowHandle, windowShowState);

	while (TRUE) {

		while (PeekMessage(&message, NULL, 0, 0, PM_REMOVE)) {

			switch (message.message) {

			case WM_QUIT:
				return (int) message.wParam;
				break;
			}

			DispatchMessage(&message);
		}
	}
}

LRESULT CALLBACK WindowProcedure(HWND windowHandle, UINT message,
	WPARAM wordParameter, LPARAM longParameter) {

	switch (message) {

	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}

	return DefWindowProc(windowHandle, message, wordParameter, longParameter);
}
