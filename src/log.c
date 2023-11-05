#include "log.h"

// TODO: Enable live monitoring of log file by another process
FILE* logFile = NULL;
FILE* latestLogFile = NULL;

void LogMessage(char* message) {

	if (!logFile) {

		StartLogFile();

		if (!logFile) {

			return;
		}
	}

	fprintf(logFile, "%s\n", message);
	fprintf(latestLogFile, "%s\n", message);
}

void StartLogFile(void) {

	#define FILE_PATH_LENGTH 64

	time_t dateTimeRaw;
	struct tm dateTimeTM;
	char logFilePath[FILE_PATH_LENGTH];
	char latestLogFilePath[FILE_PATH_LENGTH];

	if (!PathFileExistsA(LOG_FOLDER)) {

		CreateDirectoryA(LOG_FOLDER, NULL);
	}

	time(&dateTimeRaw);
	localtime_s(&dateTimeTM, &dateTimeRaw);

	sprintf_s(logFilePath, FILE_PATH_LENGTH,
		"%s\\Physio_%04d-%02d-%02d_%02d-%02d-%02d.txt", LOG_FOLDER,
		dateTimeTM.tm_year + 1900, dateTimeTM.tm_mon, dateTimeTM.tm_mday,
		dateTimeTM.tm_hour, dateTimeTM.tm_min, dateTimeTM.tm_sec);
	sprintf_s(latestLogFilePath, FILE_PATH_LENGTH,
		"%s\\Physio_latest.txt", LOG_FOLDER);

	fopen_s(&logFile, logFilePath, "w");
	fopen_s(&latestLogFile, latestLogFilePath, "w");

	#undef FILE_PATH_LENGTH
}
