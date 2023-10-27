#include <windows.h> // Win32 API

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM); // Window procedure

// Entry point
int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	PWSTR pCmdLine, int nCmdShow) {

	// Decide window title and icon
	PWSTR wTitle = L"Physio";
	HICON wIcon = LoadIcon(NULL, IDI_APPLICATION); // Default icon

	// Decide window size and location
	int cxScreen = GetSystemMetrics(SM_CXSCREEN); // Screen size - X
	int cyScreen = GetSystemMetrics(SM_CYSCREEN); // Screen size - Y
	int cxWindow = 1024; // Window size - X
	int cyWindow = 768;	 // Window size - Y
	int xWindow = (cxScreen - cxWindow) / 2; // Window location - X
	int yWindow = (cyScreen - cyWindow) / 2; // Window location - Y

	WNDCLASS wc; // Window class
	HWND hWnd;	  // Window handle
	MSG Msg;	  // Current message

	// Register window class
	wc.style		 = 0; // No paint on window resize
	wc.cbClsExtra	 = 0;
	wc.cbWndExtra	 = 0;
	wc.lpszClassName = L"GameWindow";
	wc.hInstance	 = hInstance;
	wc.hbrBackground = NULL; // No background brush
	wc.lpszMenuName	 = NULL;
	wc.lpfnWndProc	 = WndProc;
	wc.hCursor		 = LoadCursor(NULL, IDC_ARROW); // Default cursor
	wc.hIcon		 = wIcon;
	RegisterClass(&wc);

	// Initialize the window
	hWnd = CreateWindow(wc.lpszClassName, wTitle,
		WS_OVERLAPPEDWINDOW | WS_VISIBLE,
		xWindow, yWindow, cxWindow, cyWindow,
		NULL, NULL, hInstance, NULL);
	ShowWindow(hWnd, nCmdShow); // Respect shortcut "Run" setting

	// Main loop
	while (TRUE) {

		// Message loop
		while (PeekMessage(&Msg, NULL, 0, 0, PM_REMOVE)) {

			// Check for quit message
			if (Msg.message == WM_QUIT) {

				// Set application exit code and quit
				return Msg.wParam;
			}

			// Dispatch message to window procedure
			DispatchMessage(&Msg);
		}
	}
}

// Window procedure
LRESULT CALLBACK WndProc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam) {

	switch(Msg) {

		// Window closed
		case WM_DESTROY:
		PostQuitMessage(0); // Posts WM_QUIT with exit code
		break;
	}

	// Process message with default window procedure
	return DefWindowProc(hWnd, Msg, wParam, lParam);
}
