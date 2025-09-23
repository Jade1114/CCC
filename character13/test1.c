#include <stdio.h>
#include <stdlib.h>

int main(void) {

	int *dynamic_arr = (int *)malloc(5 * sizeof(int));
	if (dynamic_arr == NULL) {
		perror("动态数组分配失败");
		exit(EXIT_FAILURE);
	}

	for (size_t i = 0; i < 5; i++) {
		dynamic_arr[i] = (i + 1) * 10;
	}
	puts("动态数组的内容: \n");
	for (size_t i = 0; i < 5; i++) {
		printf("%d ", dynamic_arr[i]);
	}
	return 0;
}