#include <errno.h>
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	FILE *file_ptr = NULL;

	file_ptr = fopen("123.txt", "w");

	if (file_ptr == NULL) {
		perror("Failed to open file");
		return EXIT_FAILURE;
	}

	// fputc() fputs() fprintf()

	fputc('H', file_ptr);
	fputc('i', file_ptr);
	fputc('\n', file_ptr);

	fputs("This is a line written by fputs.\n", file_ptr);

	double pi = 3.14;

	fprintf(file_ptr, "Numbers: %d, %f, %s\n", 10, pi, "End of example.");

	fclose(file_ptr);

	puts("File '123.txt' has benn written successfully!\n");

	return 0;
}