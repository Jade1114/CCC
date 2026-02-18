#include <assert.h>
#include <errno.h>
#include <inttypes.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(int argc, char *argv[]) {
    // 命令行参数

    printf("Program name: %s\n", argv[0]);
    printf("You have entered %d arguments:\n ", argc - 1);

    for (size_t i = 0; i < argc; i++) {
        printf("Argument %d: %s\n", i, argv[i]);
    }

    system("pause");

    return EXIT_SUCCESS;
}