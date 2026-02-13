#include <errno.h>
#include <inttypes.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// 可变参数
// double average(double a ,double b)

/**
 * 计算平均数.
 * @param num_args 参数的变量
 * @param ... 可变参数列表，即要计算平均的数字
 * @return 平均数
 */
double average(int num_ages, ...);

int main(void) {

    printf("Ave 2,3,4,5 = %f\n", average(4, 2, 3, 4, 5));

    // 日志记录
    // snprintf
    return EXIT_SUCCESS;
}

double average(int num_args, ...) {
    double sum = 0.0;
    va_list args;

    va_start(args, num_args);

    for (size_t i = 0; i < num_args; i++) {
        sum += va_arg(args, int); // va_args获取下一个参数
    }

    va_end(args);

    return num_args > 0 ? sum / num_args : 0;
}