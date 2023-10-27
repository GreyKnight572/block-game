#include <windows.h> // Win32 API

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM); // Window procedure

// Entry point
int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	PWSTR pCmdLine, int nCmdShow) {

	WNDCLASSW wc; // Window class
	HWND hwnd;	  // Window handle
	MSG msg;	  // Current message

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
	wc.hIcon		 = LoadIcon(NULL, IDI_APPLICATION); // Default icon
	RegisterClassW(&wc);

	// Create the window
	int scX = GetSystemMetrics(SM_CXSCREEN);
	int scY = GetSystemMetrics(SM_CYSCREEN);
	int szX = 1024;
	int szY = 768;
	int cnX = (scX - szX) / 2;
	int cnY = (scY - szY) / 2;
	hwnd = CreateWindowW(wc.lpszClassName, L"Physio",
		WS_OVERLAPPEDWINDOW | WS_VISIBLE, cnX, cnY, szX, szY, // Corner, size
		NULL, NULL, hInstance, NULL);
	ShowWindow(hwnd, nCmdShow); // Respects shortcut run settings

	// Main loop
	while (TRUE) {

		// Message loop
		while (PeekMessageA(&msg, NULL, 0, 0, PM_REMOVE)) {

			// Check for quit message
			if (msg.message == WM_QUIT) {

				// Set application exit code and quit
				return msg.wParam;
			}

			// Dispatch message to window procedure
			DispatchMessage(&msg);
		}
	}
}

// Window procedure
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {

	switch(msg) {

		// Window closed
		case WM_DESTROY:
		PostQuitMessage(0); // Posts WM_QUIT with exit code
		break;
	}

	// Process message with default window procedure
	return DefWindowProcW(hwnd, msg, wParam, lParam);
}
