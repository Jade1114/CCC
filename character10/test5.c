#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void read_config_safe(const char *file_name);

int main(void) {

	const char *file_name = "123.txt";

	read_config_safe(file_name);

	return 0;
}

void read_config_safe(const char *file_name) {
	FILE *file_ptr = NULL;
	file_ptr = fopen(file_name, "r");

	if (file_ptr == NULL) {
		char error_msg[256];

		strerror_r(errno, error_msg, sizeof(error_msg));

		fprintf(stderr, "Failed to open config file for readding: %s\n", error_msg);

		exit(EXIT_FAILURE);
	}

	char buffer[256];
	while (fgets(buffer, sizeof(buffer), file_ptr) != NULL) {
		printf("%s", buffer);
	}

	fclose(file_ptr);
}