#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 结构体中的指针成员 Pointer Member in a struct

typedef struct {
    int *data; // 指针成员（指向动态分配的内存）
} Example;

typedef struct {
    int id;
    char *title;
    float price;
} Book;

// char title[50]; -> 编译的时候，必须明确说明size大小
// 当声明的size过于大时，会占据大量空间，连续不断的空间
// 甚至空间被浪费
// 静态内存 -> 栈

// 动态内存 -> 堆 (heap) 申请内存
// stack 栈
// heap 堆
// 代码区
// 静态区(static)( 全局区 )

int main(void) {

    int n;

    printf("input number:\n");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));

    if (arr == NULL) {
        fprintf(stderr, "内存分配失败!\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;
    }

    printf("数组内容: \n");

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");

    for (int i = 0; i < n; i++) {
        printf("%p \n", &arr[i]);
    }

    printf(("\n"));

    free(arr);
    arr = NULL;

    return 0;
}
