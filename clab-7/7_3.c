#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int **getArray(int n) {
    srand((unsigned) time(NULL));
    int **array = (int **) malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        array[i] = (int *) malloc(n * sizeof(int));
    }
    if (array == NULL) {
        printf("Memory error");
        exit(1);
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            array[i][j] = -100 + rand() % (100 - -100 + 1);
        }
    }

    return array;
}

int maximal(int a, int b) {
    if (a > b) return a;
    return b;
}

int foundMMaximalElement(int *array, int n) {
    int max = array[0];
    for (int i = 0; i < n; ++i) {
        max = maximal(max, array[i]);
    }
    return max;
}


int *getMinimalArrayFromMatrix(int **array, int n) {
    int *resultArray = (int *) malloc(n * sizeof(int));
    for (int i = 0; i < n; ++i) {
        resultArray[i] = foundMMaximalElement(array[i], n);
    }
    return resultArray;
}

int main() {
    int n;
    do {
        printf("Enter n: ");
        scanf("%d", &n);
    } while (n <= 0);
    int **array = getArray(n);
    int *result = getMinimalArrayFromMatrix(array, n);
    for (int i = 0; i < n; ++i) {
        printf("%d ", result[i]);
    }
    return 0;
}
