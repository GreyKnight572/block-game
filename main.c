#include <windows.h>
#include <wchar.h>

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow) {
	wprintf(L"Arguments: %ls\n", pCmdLine);
	return 0;
}
