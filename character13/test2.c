#include <errno.h>
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// realoc();

void printBudgets(double *budgets, int size);

int main(void) {

	int size = 3;
	double *budgets = (double *)malloc(size * sizeof(double));
	if (budgets == NULL) {
		perror("Failed to allocate initial budgets");
		return EXIT_FAILURE;
	}

	budgets[0] = 10000;
	budgets[1] = 15000;
	budgets[2] = 12000;

	printBudgets(budgets, size);

	int newSize = 5;
	double *newBudgets = (double *)realloc(budgets, newSize * sizeof(double));

	if (newBudgets == NULL) {
		perror("Failed to rallocate initial budgets");
		free(budgets);
		return EXIT_FAILURE;
	}

	free(budgets);
	return EXIT_SUCCESS;
}

void printBudgets(double *budgets, int size) {
	printf("Current budgets: \n");
	for (size_t i = 0; i < size; i++) {
		printf("%.2f\n", budgets[i]);
	}
}