#include <errno.h>
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	FILE *file_stream = NULL;

	char buffer[256];

	file_stream = fopen("132.txt", "r");

	if (file_stream == NULL) {
		perror("Error opening file");
		return EXIT_FAILURE;
	}

	while (fgets(buffer, sizeof(buffer), file_stream) != NULL) {
		printf("%s", buffer);
	}

	memset(buffer, 0, sizeof(buffer));

	printf("\n");

	rewind(file_stream);

	int ch;

	while ((ch = fgetc(file_stream)) != EOF) {
		putchar(ch);
	}

	if (fclose(file_stream) != 0) {
		perror("Error closing file");
		return EXIT_FAILURE;
	}
}