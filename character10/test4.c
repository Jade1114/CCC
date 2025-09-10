#include <stdio.h>
#include <stdlib.h>

int main(void) {

	const char *file_name = "123.txt";

	FILE *file_ptr;

	file_ptr = fopen("123.txt", "r");

	if (file_ptr == NULL) {
		perror("cant open the file");
		return EXIT_FAILURE;
	}

	// ferror
	// feof
	// clearerr

	char buffer[100];

	while (fgets(buffer, sizeof(buffer), file_ptr) != NULL) {
		printf("%s", buffer);
	}

	if (ferror(file_ptr)) {
		perror("occuring a error when reading the file");
		clearerr(file_ptr);
	}

	if (feof(file_ptr)) {
		printf("file come to the EOF!");
	} else {
		printf("file can't come to the EOF!");
	}

	fclose(file_ptr);

	return 0;
}