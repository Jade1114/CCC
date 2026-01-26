#pragma once

#include <stddef.h> // for size_t

// 架构师会预留一些参数
typedef int (*CompareFunc)(const void *, const void *, void *context);

void genericSort(void *array, size_t length, size_t size, CompareFunc compare,void *context);
