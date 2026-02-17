// #define NDEBUG // 禁用debug版本
#include <assert.h>
#include <errno.h>
#include <inttypes.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// 用于开发阶段的错误捕获
// 发布之后，所有的断言全都不奏效了
// assert 断言

// 发布版本通常直接禁用断言

int main(void) {

    int a = 5;
    assert(a == 5);

    a = 3;

    assert(a == 5);

    puts("hello"); // debug版本，该语句不会执行， release版本，该语句会执行

    return EXIT_SUCCESS;
}