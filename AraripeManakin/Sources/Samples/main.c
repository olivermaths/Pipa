#include "../Log/Include/Log.h"

int main() {

	ARMK_Debug("This is a debug message! %s %d %f\n", "Welcome!!!", 2, 2.5);
	ARMK_Trace("This is a trace message! %s %d %f\n", "Welcome!!!", 2, 2.5);
	armk_log(armk_info, "This is a info message! %s %d %f\n", "Welcome!!!", 2, 2.5);
	armk_log(armk_warning, "This is a warning message! %s %d %f\n", "Welcome!!!", 2, 2.5);
	armk_log(armk_error, "This is a error message! %s %d %f\n", "Welcome!!!", 2, 2.5);
	armk_log(armk_fatal, "This is a fatal message! %s %d %f\n", "Welcome!!!", 2, 2.5);
	
	return 0;
}