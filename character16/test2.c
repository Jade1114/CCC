#include <assert.h>
#include <errno.h>
#include <inttypes.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// 在一个给定整数数组中寻找元素最大值
int findMaxmun(int *arr, int length);

int main(void) {

    int numbers[] = {3, 1, 5, 6, 10, 2, 4, 7};

    int max = findMaxmun(numbers, sizeof(numbers) / sizeof(numbers[0]));

    printf("The maximum number is %d", max);

    findMaxmun(NULL, 0);

    return EXIT_SUCCESS;
}

int findMaxmun(int *arr, int length) {
    assert(arr != NULL && length > 0);

    int max = arr[0];

    for (size_t i = 0; i < length; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}