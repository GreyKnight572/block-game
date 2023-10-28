// Header guard
#ifndef HG_LOG
#define HG_LOG

// System library headers
#include <stdio.h>
#include <shlwapi.h>

// System library files
#pragma comment(lib, "Shlwapi.lib")

void LogMessage(char* message);

FILE* log_file; // Global log file

#endif
