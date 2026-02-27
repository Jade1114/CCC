#include <stdio.h>
#define ROWS 3
#define COLS 4

// 传递过来的数组的列数已经确定
void print_matrix(int (*matrix)[COLS], int rows);
void p2(int matrix[][COLS], int rows);
void p3(int matrix, int rows, int cols);
void p4(int **matrix, int rows, int cols);

void flip_image(int (*image)[COLS], int rows, int cols);

int main(void) {

    int arr[ROWS][COLS] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};

    print_matrix(arr, ROWS);

    flip_image(arr, ROWS, COLS);

    print_matrix(arr, ROWS);

    return 0;
}

void print_matrix(int (*matrix)[COLS], int rows) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void flip_image(int (*image)[COLS], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols / 2; j++) {
            // 交换对称列
            int temp = image[i][j];
            // 镜像索引 (symmteric index)
            image[i][j] = image[i][cols - 1 - j];
            image[i][cols - 1 - j] = temp;
        }
    }
}
