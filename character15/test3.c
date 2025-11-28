#include <errno.h>
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// 比较函数，比较两个数
// 高可用
// 泛型编程

// int compare_ints(const int a, const int b);
// int compare_double(double a, double b);
// ...

// void*
// Array<T> array = .....

int compare_value(const void *a, const void *b);

void generic_sort(void *array, size_t element_size, size_t element_count,
                  int (*compare)(const void *, const void *));

int main(void) {
    int ints[] = {-2, 90, 0, 123, -123, 3, 41, 2};
    size_t ints_count = sizeof(ints) / sizeof(ints[0]);

    int num1 = 1;
    int num2 = 2;

    printf("%d\n", compare_value(&num1, &num2));

    generic_sort(ints, sizeof(ints[0]), ints_count, compare_value);

    for (size_t i = 0; i < ints_count; i++) {
        printf("%d ", ints[i]);
    }

    printf("\n");

    return EXIT_SUCCESS;
}

// int compare_ints(const int a, const int b) {
//     if (a < b)
//         return -1;
//     if (a > b)
//         return 1;
// }

// 强制类型转换成int类型

int compare_value(const void *a, const void *b) {
    int arg1 = *(const int *)a;
    int arg2 = *(const int *)b;
    if (arg1 < arg2)
        return -1;
    if (arg1 > arg2)
        return 1;
}

void generic_sort(void *array, size_t element_size, size_t element_count,
                  int (*compare)(const void *, const void *)) {
    qsort(array, element_size, element_count, compare);
}