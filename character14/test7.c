#include <errno.h>
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// void (*Callback) (int);

typedef void (*Callback)(int);

void traverse(int *array, int size, Callback callback);
// void traverse(int* array,int size,Student* s);
// void traverse(int* array, int size,int* number);

void printElement(int element);
void doubleElement(int element);
void checkIfEven(int element);

// int add(int a) { return a; }

int main(void) {

    int numbers[] = {1, 2, 3, 4, 5};

    // 回调函数：是你传递给另一个函数的函数，这允许在后者中调用前者
    // 这种机制让你能够在不同的时间点或者条件下，根据需要执行特定的功能
    // 为什么使用回调函数：代码更加灵活和可重用（分模块）
    // 因为你可以根据不同的情况动态地改变执行操作

    int size = sizeof(numbers) / sizeof(numbers[0]);

    traverse(numbers, size, printElement);

    traverse(numbers, size, doubleElement);

    traverse(numbers, size, checkIfEven);

    return EXIT_SUCCESS;
}
void traverse(int *array, int size, Callback callback) {
    for (int i = 0; i < size; i++) {
        callback(array[i]);
        // printElement();
        // doubleElement();
        // checkIfEven(array[i]);
    }
}

void printElement(int element) { printf("%d\n", element); }

void doubleElement(int element) {
    printf("%d doubled is %d\n", element, element * 2);
}

void checkIfEven(int element) {
    if (element % 2 == 0) {
        printf("%d is even\n", element);
    } else {
        printf("%d is odd\n", element);
    }
}