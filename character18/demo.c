#include <assert.h>
#include <ctype.h>
#include <errno.h>
#include <inttypes.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define ROWS 3
#define COLS 4
#define MAX_NAME 50

typedef struct {
    char name[MAX_NAME];
    int age;
} Person;

// static

static void print_2d_array(size_t rows, size_t cols, int (*arr)[COLS]);
//                                      int [ROWS][COLS]

static void modify_person_array(Person *people, size_t size);

static int compare_persons(const void *a, const void *b);

static void greet(const char *name);

static void farewell(const char *name);

typedef void (*MessageFunc)(const char *);

int main(void) {

    // 1. 数组作为函数参数：传递（大）数据集，共享内存数据
    // 2. 函数指针：多态性，回调函数，动态调用
    //

    int martix[ROWS][COLS] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {1, 2, 3, 5}};

    printf("2D Array:\n");
    print_2d_array(ROWS, COLS, martix);
    printf("\n");

    Person people[] = {{"Alice", 30}, {"Bob", 25}, {"Charlie", 35}};

    size_t num_people = sizeof(people) / sizeof(people[0]);

    printf("Before modification: \n");

    for (size_t i = 0; i < num_people; i++) {
        printf("%s: %d\n", people[i].name, people[i].age);
    }

    modify_person_array(people, num_people);
    printf("After modification: \n");

    for (size_t i = 0; i < num_people; i++) {
        printf("%s: %d\n", people[i].name, people[i].age);
    }

    qsort(people, num_people, sizeof(Person), compare_persons);
    printf("After sorting by age: \n");

    for (size_t i = 0; i < num_people; i++) {
        printf("%s: %d\n", people[i].name, people[i].age);
    }

    MessageFunc message[] = {greet, farewell};

    const char *name = "David";

    printf("\nFunction pointer array demonstration:\n");

    for (size_t i = 0; i < sizeof(message) / sizeof(message[0]); i++) {
        message[i](name);
    }

    return EXIT_SUCCESS;
}

static void print_2d_array(size_t rows, size_t cols, int (*arr)[COLS]) {
    if (rows == 0 || cols == 0) {
        return;
    }

    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

static void modify_person_array(Person *people, size_t size) {
    for (size_t i = 0; i < size; i++) {
        people[i].age += 1;
    }
}

static int compare_persons(const void *a, const void *b) {
    // qsort
    return ((const Person *)a)->age - ((const Person *)b)->age;
}

static void greet(const char *name) { printf("Hello, %s!\n", name); }

static void farewell(const char *name) { printf("Goodbye,%s!\n", name); }
