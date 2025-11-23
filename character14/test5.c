#include <errno.h>
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// 函数指针(Function Pointer)
// 如何声明一个指针指向函数呢？
// 返回类型 （*指针变量名） （参数类型）;

int (*myFunctionPointer)(int, int);
// myFunctionPointer -> int f(int num1,int num2)
int add(int a, int b);

int main(void)
{

    // 指向函数
    myFunctionPointer = add;

    // 指针 变量，数组，字符串，结构体，指针
    //
    // 通过指针调用函数

    int result = myFunctionPointer(2, 3);

    printf("The result is %d\n", result);

    // 函数指针的用途：实现回调函数
    // 回调函数允许你将一个函数作为参数传递给另一个函数，这样，当特定的事件发生时候，可以调用传递的参数
    // 事件驱动编程

    return EXIT_SUCCESS;
}

int add(int a, int b) { return a + b; }