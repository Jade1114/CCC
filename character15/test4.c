#include <errno.h>
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int *global_ptr;

void function() {
    int local = 5;
    int *local_ptr = &local;
    global_ptr = (int *)malloc(sizeof(int));

    if (global_ptr != NULL) {
        *global_ptr = 10;
    }

    printf("Inside function: local_ptr points to %d\n", *local_ptr);
}

int mian(void) {
    // 指针的作用域和生命周期

    function();

    printf("Outside function: global_ptr points to %d\n", *global_ptr);

    free(global_ptr);

    return EXIT_SUCCESS;
}