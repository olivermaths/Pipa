#include "Include/Window.h"

struct SopranoWindow CreateSopranoWindow(const char* class_name, const char* window_name) {
	HINSTANCE hInstance = GetModuleHandle(0);
	WNDCLASS wc = {
		.style = CS_HREDRAW | CS_VREDRAW,
		.hCursor = LoadCursor(NULL, IDC_ARROW),
		.lpfnWndProc = DefWindowProc,
		.hInstance = hInstance,
		.lpszClassName = class_name
	};
	RegisterClass(&wc);


	HWND hwnd = CreateWindowEx(
		0,
		class_name,
		window_name,
		WS_OVERLAPPED,
		CW_USEDEFAULT, CW_USEDEFAULT, 800, 600,
		NULL,
		NULL,
		hInstance,
		NULL
		
	);
	if (hwnd == NULL) {
		printf("failed to create window\n");
		exit(0);
	}
	struct SopranoWindow win = {
		.instance = hInstance,
		.hwnd = hwnd,
		.data.width = 800,
		.data.heigh = 600
	};
	ShowWindow(hwnd, SW_SHOW);
	return win;
}

void DestroySopranoWindow(const struct SopranoWindow *win, const char* class_name) {
	if (!DestroyWindow(win->hwnd)) {
		printf("failed to close window!!\n");
		exit(0);
	};
	if (!UnregisterClass(class_name, win->instance)) {
		printf("failed to close unregister window class!!\n");
		exit(0);
	}
	printf("window closed! and it workd!\n");
}