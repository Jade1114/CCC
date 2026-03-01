#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 组合 Composition 或 包含 Containment
typedef struct {
    int id;
    char *title; // char title[50]; -> 动态分配的书名
    // 聚合 Aggregation
    // 析构
    double price;
} Book;

typedef struct {
    // Book books; -> 嵌套 Nesting
    Book *books; // books 指向一个动态分配的书籍数组
    // 动态数组 Dynamic Array

    // 自引用 Self-Referencing
    // 链式结构 Linked Structure
    size_t count;    // 当前书籍的数量
    size_t capacity; // 当前可容纳的最大的书籍数量
} Library;

typedef enum {
    SUCCESS = 0,
    MEMORY_ERROR,
    INVALID_PARAMS,
    DUPLICATE_ID,
    NOT_FOUND
} ErrorCode;

// 构造函数 Constructor
Library create_library(size_t initial_capacity, ErrorCode *error) {
    Library lib = {0};

    if (initial_capacity == 0) {
        *error = INVALID_PARAMS;
        return lib;
    }

    lib.books = (Book *)malloc(initial_capacity * sizeof(Book));
    if (!lib.books) {
        *error = MEMORY_ERROR;
        return lib;
    }

    lib.count = 0;
    lib.capacity = initial_capacity;

    *error = SUCCESS;
    return lib;
}

ErrorCode add_book(Library *lib, int id, const char *title, double price) {
    if (!lib || !title || price < 0) {
        return INVALID_PARAMS;
    }

    for (size_t i = 0; i < lib->count; i++) {
        if (lib->books[i].id == id) {
            return DUPLICATE_ID;
        }
    }

    // 是否需要扩容？
    if (lib->count >= lib->capacity) {
        size_t new_capacity = lib->capacity * 2;
        Book *temp = (Book *)realloc(lib->books, new_capacity * sizeof(Book));
        if (!temp) {
            return MEMORY_ERROR;
        }

        lib->books = temp;
        lib->capacity = new_capacity;
    }

    // 分配书名的内存
    char *new_title = (char *)malloc(strlen(title) + 1);
    if (!new_title) {
        return MEMORY_ERROR;
    }
    strcpy(new_title, title);

    lib->books[lib->count].id = id;
    lib->books[lib->count].title = title;
    lib->books[lib->count].price = price;
    lib->count++;

    return SUCCESS;
}

Book *find_book(const Library *lib, int id, ErrorCode *error) {
    if (!lib) {
        *error = INVALID_PARAMS;
        return NULL;
    }

    for (size_t i = 0; i < lib->count; i++) {
        if (lib->books[i].id == id) {
            return &lib->books[i];
        }
    }

    *error = NOT_FOUND;
    return NULL;
}

void print_library(const Library *lib) {
    if (!lib) {
        printf("错误：无效的图书馆! \n");
        return;
    }

    printf("\n图书馆藏书数量: %zu\n", lib->count);
    for (size_t i = 0; i < lib->count; i++) {
        printf("\n书籍 #%zu\n", i + 1);
        printf("ID:%d\n", lib->books[i].id);
        printf("Title: %s\n", lib->books[i].title);
        printf("Price: %lf\n", lib->books[i].price);
        printf("========================\n");
    }
}

// 析构函数 Destructor
void free_library(Library *lib) {
    if (!lib) {
        return;
    }

    if (lib->books) {
        for (size_t i = 0; i < lib->count; i++) {
            if (lib->books[i].title) {
                free(lib->books[i].title);
                lib->books[i].title = NULL;
            }
        }

        free(lib->books);
    }

    lib->books = NULL;
    lib->count = 0;
    lib->capacity = 0;
}

int main(void) {

    ErrorCode error;

    Library lib = create_library(2, &error);

    if (error != SUCCESS) {
        printf("创建图书馆失败，错误码: %d\n", error);
        return 1;
    }

    error = add_book(&lib, 1, "C++", 24.99);
    if (error != SUCCESS) {
        printf("添加图书失败，错误码: %d\n", error);
        free_library(&lib);
        return 1;
    }

    error = add_book(&lib, 2, "Java", 35.99);
    if (error != SUCCESS) {
        printf("添加图书失败，错误码: %d\n", error);
        free_library(&lib);
        return 1;
    }

    print_library(&lib);

    printf("capacity: %zu \n", lib.capacity);

    free_library(&lib);

    return 0;
}
