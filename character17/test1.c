#include <assert.h>
#include <errno.h>
#include <inttypes.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(void) {
    // C语言中的环境变量的访问

    // const char *path = getenv("PATH");
    // if (path != NULL) {
    //     printf("PATH: %s\n", path);
    // } else {
    //     return -1;
    // }

    setenv();

    // ---
    return EXIT_SUCCESS;
}