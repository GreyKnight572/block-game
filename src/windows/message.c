#include "message.h"

LRESULT CALLBACK MainWindowProcedure(HWND windowHandle, UINT message,
	WPARAM wordParameter, LPARAM longParameter) {

	switch (message) {

	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}

	return DefWindowProcA(windowHandle, message, wordParameter, longParameter);
}
