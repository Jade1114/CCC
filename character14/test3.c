// 三级指针案例：字符串无限追加的应用
#include <stdio.h>
#include <inttypes.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void addString(char ***array, int *size, char *str);
void printStrings(char **array, int size);

int main(void)
{
    char **strArray = NULL;

    int size = 0;

    addString(&strArray, &size, "Hello");
    addString(&strArray, &size, "World");

    printStrings(strArray, size);

    // 清除内存空间
    for (size_t i = 0; i < size; i++)
    {
        free(strArray[i]);
    }

    free(strArray);

    return EXIT_SUCCESS;
}

void addString(char ***array, int *size, char *str)
{
    char **temp = realloc(*array, (*size + 1) * sizeof(char *));

    if (temp == NULL)
    {
        printf("Failed to allocate memory!\n");
        return;
    }

    *array = temp;

    // 分配内存并且复制字符串
    (*array)[*size] = malloc(strlen(str) + 1);
    strcpy((*array)[*size], str);
    (*size)++;
}

void printStrings(char **array, int size)
{
    for (size_t i = 0; i < size; i++)
    {
        printf("%s", array[i]);
    }
}