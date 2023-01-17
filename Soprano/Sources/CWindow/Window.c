#if _WIN32
#include "Include/Window.h"
#include "stdlib.h"
#include <windows.h>
#include <stdio.h>

#define MAX_WINDOW_CONTEXT 5
static LPCWSTR __spClassName = L"Soprano Window Class";

struct PlaftormContext {
	HINSTANCE instance;
	HWND hwnd;
};

struct SopranoWindowPointer {
	char *win_name;
	void* win_ptr;
};

struct SopranoWindowContext{ 
	void* pointer;
	struct SopranoWindowPointer contexts[MAX_WINDOW_CONTEXT];
};


static struct SopranoWindowContext currentContext = {
	.pointer = NULL,
	.contexts = NULL,
};


struct SopranoWindow createSopranoWindow(const char* window_name, int width, int height) {
	
	struct PlaftormContext *ic = malloc(sizeof(struct PlaftormContext));
	if (ic == NULL) {
		MessageBox(0, L"Program run out of memory", L"Fatal Error", MB_ICONEXCLAMATION | MB_OK);
		exit(0);
	};

	
	ic->instance = GetModuleHandle(0);
	
	WNDCLASS wc = {
		.hIcon = LoadIcon(ic->instance,IDI_APPLICATION),
		.style = CS_HREDRAW | CS_VREDRAW,
		.hCursor = LoadCursor(NULL, IDC_ARROW),
		.lpfnWndProc = DefWindowProc,
		.hInstance = ic->instance,
		.lpszClassName = __spClassName
	};
	RegisterClass(&wc);


	ic->hwnd = CreateWindowEx(
		0,
		__spClassName,
		window_name,
		WS_OVERLAPPED,
		CW_USEDEFAULT, CW_USEDEFAULT, width, height,
		NULL,
		NULL,
		ic->instance,
		NULL
		
	);
	if (ic->hwnd == NULL) {
		MessageBox(0, L"Failed  to create a new Window!", L"Fatal Error", MB_ICONEXCLAMATION | MB_OK);
		exit(0);
	}
	struct SopranoWindow win = {
		.plaftormContext = ic,
		.data.width = width,
		.data.height = height
	};
	ShowWindow(ic->hwnd, SW_SHOW);
	return win;
}

void destroySopranoWindow(const struct SopranoWindow *win) {
	struct PlaftormContext* ic = win->plaftormContext;
	if (!DestroyWindow(ic->hwnd)) {
		MessageBox(0, L"Failed  to Close Window!", L"Fatal Error", MB_ICONEXCLAMATION | MB_OK);
		exit(0);
	};
	if (!UnregisterClass(__spClassName, ic->instance)) {
		MessageBox(0, L"Failed  to UnregisterClass!", L"Fatal Error", MB_ICONEXCLAMATION | MB_OK);
		exit(0);
	}
	printf("Window Closed!!");
}

#endif