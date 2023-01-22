enum ARMK_LogLevel {
	armk_debug = 0,
	armk_trace,
	armk_info,
	armk_warning,
	armk_error,
	armk_fatal
};

_Bool armk_log(enum ARMK_LogLevel level, const char* message, ...);


#ifdef _DEBUG
#define ARMK_Debug(fmt, ...) armk_log(armk_debug, fmt, __VA_ARGS__)
#define ARMK_Trace(fmt, ...) armk_log(armk_trace, fmt, __VA_ARGS__)
#else 
#define ARMK_Debug(fmt, ...)
#define ARMK_Trace(fmt, ...)
#endif
									
								