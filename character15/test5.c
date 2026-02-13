#include <errno.h>
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// 悬挂指针 Dangling pointer

int main(void) {

    int *ptr = (int *)malloc(sizeof(int));

    if (ptr == NULL) {

        printf("Memory allocation failed\n");
        return EXIT_FAILURE;
    }

    *ptr = 10;

    printf("Value at ptr: %d\n", *ptr);

    free(ptr);

    // 此时ptr成为悬挂指针
    // 如果此时再访问悬挂指针 ，非常危险，不应该在实际编程中使用

    printf("Value at ptr: %d\n", *ptr);

    return EXIT_SUCCESS;
}