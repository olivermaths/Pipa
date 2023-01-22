#pragma once


struct ARMK_Window {
	void* plaftormContext;
	struct {
		int width;
		int height;
	} data;
};

struct ARMK_Window		armk_createWindow(const char* window_name, int width, int height);
void                    armk_destroyWindow(const struct ARMK_Window* win);



#if __linux__
@not implemented yet
#elif __APPLE__
@not implemented yet
#endif