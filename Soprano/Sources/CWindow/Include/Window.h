#pragma once


struct SopranoWindow {
	void* plaftormContext;
	struct {
		int width;
		int height;
	} data;
};

struct SopranoWindow createSopranoWindow(const char* window_name, int width, int height);
void                 destroySopranoWindow(const struct SopranoWindow * win);


#if __linux__
@not implemented yet
#elif __APPLE__
@not implemented yet
#endif