#include <windows.h> // Win32 API

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM); // Window procedure

// Entry point
int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	PWSTR pCmdLine, int nCmdShow) {

	WNDCLASSW wc; // Window class
	HWND hwnd;	  // Window handle
	MSG msg;	  // Current message

	// Register window class
	wc.style		 = CS_HREDRAW | CS_VREDRAW;
	wc.cbClsExtra	 = 0;
	wc.cbWndExtra	 = 0;
	wc.lpszClassName = L"Window";
	wc.hInstance	 = hInstance;
	wc.hbrBackground = GetSysColorBrush(COLOR_3DFACE);
	wc.lpszMenuName	 = NULL;
	wc.lpfnWndProc	 = WndProc;
	wc.hCursor		 = LoadCursor(NULL, IDC_ARROW);
	wc.hIcon		 = LoadIcon(NULL, IDI_APPLICATION);
	RegisterClassW(&wc);

	// Create the window
	hwnd = CreateWindowW(wc.lpszClassName, L"Block Game",
		WS_OVERLAPPEDWINDOW | WS_VISIBLE, 100, 100, 350, 250,
		NULL, NULL, hInstance, NULL);
	ShowWindow(hwnd, nCmdShow);
	UpdateWindow(hwnd);

	// Message loop
	while (GetMessage(&msg, NULL, 0, 0)) {

		// Dispatch message to window procedure
		DispatchMessage(&msg);
	}

	// Set application exit code
	return msg.wParam;
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
