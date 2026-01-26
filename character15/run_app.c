#include <errno.h>
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "compare.h"
#include "person.h"
#include "sort.h"

int main(void) {

    int intArr[] = {1, 5, 16, 64, 143, 123, 51, 67};

    const char *stringArr[] = {"banana",  "apple", "frank",
                               "chatgpt", "alma",  "olima"};

    genericSort(intArr, 8, sizeof(int), intCompare, NULL);
    genericSort(stringArr, 6, sizeof(char *), stringCompare, NULL);

    puts("\nintArr[] = ");
    for (size_t i = 0; i < 8; i++) {
        printf("%d ", intArr[i]);
    }

    puts("\nstringArr[] = ");
    for (size_t i = 0; i < 6; i++) {
        printf("%s ", stringArr[i]);
    }

    Person personArr[] = {{"Frank", 30},   {"Jade", 20}, {"Alice", 18},
                          {"Charlie", 32}, {"Dave", 52}, {"Jame", 24}};

    size_t peopleCount = sizeof(personArr) / sizeof(personArr[0]);

    CompareFunc compareFunctions[] = {compareByName, compareByAge};

    int compareChoice = 1; // 0 for name, 1 for age;

    genericSort(personArr, peopleCount, sizeof(Person),
                compareFunctions[compareChoice], NULL);

    puts("\npersonArr[] = ");
    for (size_t i = 0; i < 6; i++) {
        printf("%s, %d\n", personArr[i].name, personArr[i].age);
    }

    return EXIT_SUCCESS;
}