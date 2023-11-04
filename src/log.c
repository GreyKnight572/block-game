#include "log.h"

// TODO: Enable live monitoring of log file by another process
FILE* logFile = NULL;

void LogMessage(char* message) {

	char* logFilePath;

	if (!logFile) {

		#define MAX_STRING_LENGTH 64

		logFilePath = malloc(MAX_STRING_LENGTH * sizeof(char));

		// TODO: Change filename to Physio_YYYY-MM-DD_HH-MM-SS.txt
		GetLogFilePath(logFilePath, MAX_STRING_LENGTH, "Physio (", ").txt");
		GetLogFile(&logFile, logFilePath);

		free(logFilePath);

		if (!logFile) {

			return;
		}
	}

	fprintf(logFile, "%s\n", message);
}

void GetLogFile(FILE** logFile, char* filePath) {

	if (!PathFileExistsA(LOG_FOLDER)) {

		CreateDirectoryA(LOG_FOLDER, NULL);
	}

	fopen_s(logFile, filePath, "w");
}

void GetLogFilePath(char* logFilePath, int maxLength,
	char* prefix, char* suffix) {

	time_t currentDateTime;
	char* dateTimeStringRaw;
	char* dateTimeStringClean;

	dateTimeStringRaw = malloc(maxLength * sizeof(char));
	dateTimeStringClean = malloc(maxLength * sizeof(char));

	time(&currentDateTime);
	ctime_s(dateTimeStringRaw, maxLength, &currentDateTime);

	// TODO: Format date-time to YYYY-MM-DD_HH-MM-SS
	for (int i = 0; i < maxLength; i++) {

		switch (dateTimeStringRaw[i]) {

			case ':':
			dateTimeStringClean[i] = '-';
			break;

			case '\n':
			case '\0':
			dateTimeStringClean[i] = '\0';
			i = maxLength;
			break;

			default:
			dateTimeStringClean[i] = dateTimeStringRaw[i];
		}
	}

	sprintf_s(logFilePath, maxLength, "%s\\%s%s%s",
		LOG_FOLDER, prefix, dateTimeStringClean, suffix);

	free(dateTimeStringRaw);
	free(dateTimeStringClean);
}
