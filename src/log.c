#include "log.h" // All necessary inclusions and global declarations

// Print message to log file
void LogMessage(char* message) {

	// Check for open log file
	if (!log_file) {

		// Check for logs folder
		if (!PathFileExists("logs")) {

			// Create logs folder
			CreateDirectory("logs", NULL);
		}

		// Initialize log file and check for success
		if (fopen_s(&log_file, "logs\\log.txt", "w")) {

			// Abort logging
			return;
		}
	}

	// Print message to log file
	fprintf(log_file, "%s\n", message);
}
