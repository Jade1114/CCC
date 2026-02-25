#include <assert.h>
#include <errno.h>
#include <inttypes.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

// 变量
// 指针
// 一个指向函数的指针
// void func(int a,int b);
// void printArray(int arr[], int size);

void printArray(int* arr,int size);
// int (*arr) [N]
int main(void) {

    // c语言函数参数中的数组传递

    int numbers[] = {1,2,3,4,5,6};

    int numbers_2[] = { 1,3, 5, 619, 123};

    int numbers_3[] = {21,34,12,111,234};

    // for ... 3
    // size 不一样

    // 数组的第0个元素的地址，就是这个数组的首地址

    printArray(numbers, sizeof(numbers)/ sizeof(numbers[0]));
    printArray(numbers_2, sizeof(numbers)/ sizeof(numbers[0]));
    printArray(numbers_3, sizeof(numbers)/ sizeof(numbers[0]));
    
    


    return EXIT_SUCCESS;

}

void printArray(int* arr,int size){
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}