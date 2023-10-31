#include <windows.h>

#include "message.h"

long long HandleMessage(void* windowHandle, unsigned int message,
	unsigned long long wordParameter, long long longParameter) {

	if (message == WM_DESTROY) {

		PostQuitMessage(0);
	}

	return DefWindowProcA(windowHandle, message, wordParameter, longParameter);
}

void HandleMessages(void) {

	MSG* message;

	while (PeekMessageA(message, NULL, 0, 0, PM_REMOVE)) {

		switch ((*message).message) {

			case WM_QUIT:
			return (int) message->wParam;
		}

		DispatchMessageA(message);
	}
}
