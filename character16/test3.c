#include <assert.h>
#include <errno.h>
#include <inttypes.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void processImage(int width, int height) {

    assert(width > 50 && width < 10000);
    assert(height > 50 && height < 10000);

    if (width > 50 && height > 50) {
        printf("Processing an image of size %d x %d pixels. \n", width, height);
    }
}

int main(void) {

    processImage(1024, 768);

    // 模拟情况， w，h的值是通过指针，函数， 数组等方式进行传递的
    // 我们无法直接看到具体的值

    int w = 50, h = 50;

    processImage(w, h);

    // ---
    return EXIT_SUCCESS;
}