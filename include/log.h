#ifndef INCLUDE_GUARD_LOG_H
#define INCLUDE_GUARD_LOG_H

#include <stdio.h>
#include <time.h>

#include "Shlwapi.h"
#pragma comment(lib, "Shlwapi.lib")

#define LOG_FOLDER "logs"

void LogMessage(char* message);

void StartLogFile(void);

#endif
