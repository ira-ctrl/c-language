#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int countNegativeNumbers(int *array, int n) {
    int counter = 0;
    for (int i = 0; i < n; ++i) {
        if (array[i] < 0) counter++;
    }

    return counter;
}

int sumAfterFirstNegativeNumber(int *array, int n) {
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        if (array[i] < 0) {
            for (int j = i; j < n; ++j) {
                sum += array[j];
            }
        }
    }

    return sum;
}

int main() {
    srand((unsigned) time(NULL));
    int n;
    do {
        printf("Enter n: ");
        scanf("%d", &n);
    } while (n <= 0);

    int *array = (int *) calloc(n, sizeof(int));
    for (int i = 0; i < n; ++i) {
        array[i] = -100 + rand() % (100 - -100 + 1);
    }

    printf("\nAmount of negative numbers in an array - %d", countNegativeNumbers(array, n));
    printf("\nSummary after first negative number - %d", sumAfterFirstNegativeNumber(array, n));

    return 0;
}
