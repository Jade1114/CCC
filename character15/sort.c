// 企业案例: 自定义函数处理比较器
#define _GNU_SOURCE
#include "sort.h"

#include <stdlib.h>

// 跨平台的问题

// 包装器
static int compareWarpper(void *context, const void *a, const void *b) {
    CompareFunc compare = (CompareFunc)context;
    return compare(a, b, NULL); // Adjusted to math expeected signature
}

void genericSort(void *array, size_t length, size_t size, CompareFunc compare,
                 void *context) {

    //  qsort_r
    //  qsort_s
    //  qsort
#ifdef _WIN32
    qsort_s(array, length, size, compareWarpper, (void *)compare);
#else
    qsort_r(array, length, size, compareWarpper, context);
#endif
}