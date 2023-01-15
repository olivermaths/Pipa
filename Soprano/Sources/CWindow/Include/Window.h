#pragma once
#if _WIN64
#include "../../Include/Core.h"

struct SopranoWindow {
	HINSTANCE instance;
	HWND hwnd;
	struct {
		UINT32 width;
		UINT32 heigh;
	} data;
};

struct SopranoWindow CreateSopranoWindow(const char* class_name, const char* window_name);

void DestroySopranoWindow(const struct SopranoWindow * win, const char* class_name);


#elif __linux__
@not implemented yet
#elif __APPLE__
@not implemented yet
#endif