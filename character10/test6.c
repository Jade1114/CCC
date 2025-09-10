#include <errno.h>
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1000

int update_log_record_s(const char *filename, const char *search_str, const char *replace_str);

int main(void) {

	const char *log_file = "temp.log";
	const char *search_str = "Memory usage exceeed 80% of available memory.";
	const char *repalce_str = "[2023-02-14T12:36:00Z] [INFO] Memory usage is back to normal levels.";

	int result = update_log_record_s(log_file, search_str, repalce_str);

	return 0;
}

int update_log_record_s(const char *filename, const char *search_str, const char *replace_str) {
	if (filename == NULL || search_str == NULL || replace_str == NULL) {
		return EINVAL; // 返回无效参数错误
	}

	FILE *file_ptr = NULL;

	file_ptr = fopen(filename, "r+");

	if (file_ptr == NULL) {
		char error_msg[256];
		strerror_r(errno, error_msg, sizeof(error_msg));

		fprintf(stderr, "Failed to open config for reading: %s\n", error_msg);
		exit(EXIT_FAILURE);
	}

	char buffer[BUFFER_SIZE];
	long pos = 0;
	int found = 0;

	while (fgets(buffer, BUFFER_SIZE, file_ptr) != NULL) {
		if (strstr(buffer, search_str) != NULL) {
			found = 1;
			pos = ftell(file_ptr) - (long)strlen(buffer) - 1;
			break;
		}
	}

	if (found) {
		fseek(file_ptr, pos, SEEK_SET);
	}
}