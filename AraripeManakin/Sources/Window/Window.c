#if _WIN32
#include "Include/Window.h"
#include "../Core.h"

#define MAX_WINDOW_CONTEXT 5
static const char*  __spClassName = "Soldadinho-do-Araripe Window Class";

struct PlaftormContext {
	HINSTANCE instance;
	HWND hwnd;
};

struct AraripeManakinWindow{
	void* plaftormContext;
	struct {
		int width;
		int height;
	} data;
};

struct ARMK_WindowPointer {
	char *win_name;
	void* win_ptr;
};

struct ARMK_WindowContext{
	void* pointer;
	struct ARMK_WindowPointer contexts[MAX_WINDOW_CONTEXT];
};


static struct ARMK_WindowContext currentContext = {
	.pointer = NULL,
	.contexts = NULL,
};


struct ARMK_Window armk_createWindow(const char* window_name, int width, int height) {
	
	struct PlaftormContext *ic = malloc(sizeof(struct PlaftormContext));
	if (ic == NULL) {
		MessageBox(0, TEXT("Program run out of memory"), TEXT("Fatal Error"), MB_ICONEXCLAMATION | MB_OK);
		exit(0);
	};

	
	ic->instance = GetModuleHandle(0);
	
	WNDCLASS wc = {
		.hIcon = LoadIcon(ic->instance,IDI_APPLICATION),
		.style = CS_HREDRAW | CS_VREDRAW,
		.hCursor = LoadCursor(NULL, IDC_ARROW),
		.lpfnWndProc = DefWindowProc,
		.hInstance = ic->instance,
		.lpszClassName = (LPCWSTR)__spClassName
	};
	RegisterClass(&wc);


	ic->hwnd = CreateWindowEx(
		0,
		(LPCWSTR)__spClassName,
		(LPCWSTR)window_name,
		WS_OVERLAPPED,
		CW_USEDEFAULT, CW_USEDEFAULT, width, height,
		NULL,
		NULL,
		ic->instance,
		NULL
		
	);
	if (ic->hwnd == NULL) {
		MessageBox(0, TEXT("Failed  to create a new Window!"), TEXT("Fatal Error"), MB_ICONEXCLAMATION | MB_OK);
		exit(0);
	}
	struct ARMK_Window win = {
		.plaftormContext = ic,
		.data.width = width,
		.data.height = height
	};
	ShowWindow(ic->hwnd, SW_SHOW);
	return win;
}

void armk_destroyWindow(const struct ARMK_Window *win) {
	struct PlaftormContext* ic = win->plaftormContext;
	
	if (!DestroyWindow(ic->hwnd)) {
		MessageBox(0, TEXT("Failed  to Close Window!"), TEXT("Fatal Error"), MB_ICONEXCLAMATION | MB_OK);
		exit(0);
	};
	
	if (!UnregisterClass((LPCSTR)__spClassName, ic->instance)) {
		MessageBox(0, TEXT("Failed  to UnregisterClass!"), TEXT("Fatal Error"), MB_ICONEXCLAMATION | MB_OK);
		exit(0);
	}
}


#endif