#include "Include/Log.h"
#include "../Core.h"

#define LOG_SIZE 4096

#define ARMK_Assert(exp, message)  {                                                                           \
						if(!exp){                                                                               \
							ARMK_log(armk_fatal, "%s\n%s %li", message, __FILE__, __LINE__);                     \
							DebugBreak();																          \
						}								                                                           \
					};

inline static unsigned long armk_StrLen(const char* str){
	unsigned long count = 0;

	for (;*(str++);count++);
	return count;
}

inline static void print(const char* message, size_t size){
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	WriteFile(handle, message, size, (void*)0, 0);
}


_Bool armk_log(enum ARMK_LogLevel level, const char* fmt, ...) {
    va_list args;
    va_start(args, fmt);
    char buffer[LOG_SIZE];
    time_t now = time(NULL);
    struct tm time_info;
    localtime_s(&time_info, &now);
    strftime(buffer, 30, "%Y-%m-%d %H:%M:%S", &time_info);

    const char* level_str;
    const char* color_code;
    size_t level_str_size = 0;
    size_t color_code_size = 0;
    switch (level) {
    case armk_trace:
        level_str = "[TRACE]";
        level_str_size = 7;
        color_code = "\033[38;2;38;214;231m";
        color_code_size = 21;
        break;
    case armk_debug:
        level_str = "[DEBUG]";
        level_str_size = 7;
        color_code = "\033[38;2;154;131;240m";
        color_code_size = 19;
        break;    
    case armk_info:
        level_str = "[INFO]";
        level_str_size = 6;
        color_code = "\033[38;2;12;250;128m";
        color_code_size = 18;
        break;
    case armk_warning:
        level_str = "[WARNING]";
        level_str_size = 9;
        color_code = "\033[38;2;250;205;0m";
        color_code_size = 17;
        break;
    case armk_error:
        level_str = "[ERROR]";
        level_str_size = 7;
        color_code = "\033[38;2;240;89;45m";
        color_code_size = 17;
        break;
    case armk_fatal:
        level_str = "[FATAL]";
        level_str_size = 7;
        color_code = "\033[38;2;255;0;0m";
        color_code_size = 15;
        break;
    default:
        level_str = "[Unknown]";
        level_str_size = 9;
        color_code = "";
        break;
    }
    size_t t1 = armk_StrLen(buffer);
    buffer[t1] = ' ';
    size_t it = 0;
   
    while (color_code_size) {
        buffer[++t1] = color_code[it++];
        color_code_size--;
    }
    it = 0;

    while (level_str_size) {
        buffer[++t1] = level_str[it++];
        level_str_size--;
    }

    ++t1;
    buffer[t1++] = ' ';

    size_t formated_size = vsnprintf_s((buffer + t1), (LOG_SIZE - (t1)), _TRUNCATE, fmt, args);
    
    va_end(args);
	
    if (formated_size < 0) {
		print("Error while trying to format message\n", 38);
		exit(0);
	}

	print(buffer, (formated_size + t1 ));
    print("\033[0m", 4);
	return 1;
}