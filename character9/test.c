#include <stdio.h>
#include <string.h>

int main(void) {

	char str[] = "hello ";
	char *ptr = str;

	ptr[1] = 'a';

	printf("%s\n", str);

	while (*ptr != '\0') {
		printf("%c", *ptr);
		ptr++;
	}

	// 字符串常量
	const char *p = "hello";

	return 0;
}