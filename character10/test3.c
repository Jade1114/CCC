#include <errno.h>
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	FILE *file_ptr = NULL;

	file_ptr = fopen("123.txt", "r");

	if (file_ptr == NULL) {
		perror("Failed to open file");
		return EXIT_FAILURE;
	}

	// ftell
	// 获取当前文件指针的位置

	long position = ftell(file_ptr);
	printf("position: %ld\n", position);

	char buffer[100];

	if (fgets(buffer, sizeof(buffer), file_ptr) != NULL) {
		printf("read: %s\n", buffer);
		position = ftell(file_ptr);
		printf("position: %ld\n", position);
	}

	// fseek
	// 移动指针到指定位置
	fseek(file_ptr, 0, SEEK_SET);
	position = ftell(file_ptr);
	printf("used fseek(), position: %ld\n", position);

	// rewind
	// 移动指针到文件的开始位置

	rewind(file_ptr);
	position = ftell(file_ptr);
	printf("used rewind(), posotion: %ld\n", position);

	fclose(file_ptr);

	return 0;
}
