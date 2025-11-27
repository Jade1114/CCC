#include "math_operations.h"
#include <errno.h>
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(void) {

    int result = add(5, 6);
    printf("%d", result);
    return EXIT_SUCCESS;
}