#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int minimal(int a, int b) {
    if (a < b) {
        return a;
    }
    return b;
}

int maximal(int a, int b) {
    if (a > b) {
        return a;
    }
    return b;
}

int minimalElement(int array[], int n) {
    int min = 100;

    for (int i = 0; i < n - 1; ++i) {
        min = minimal(min, minimal(array[i], array[i + 1]));
    }

    return min;
}

int maximalElement(int array[], int n) {
    int max = 0;

    for (int i = 0; i < n - 1; ++i) {
        max = maximal(max, maximal(array[i], array[i + 1]));
    }

    return max;
}

int switchMaxAndMin(int array[], int n) {
    int max = maximalElement(array, n);
    int min = minimalElement(array, n);

    for (int i = 0; i < n; ++i) {
        if (array[i] == max) {
            array[i] = min;
        } else if (array[i] == min) {
            array[i] = max;
        }
    }

    return array;
}


int main() {
    srand((unsigned) time(0));
    int array[10];

    for (int i = 0; i < 10; ++i) {
        array[i] = -100 + rand() % (100 - -100 + 1);
        printf("[%d]%d ", i, array[i]);
    }
    switchMaxAndMin(array, 10);
    printf("\nChanged array:\n");
    for (int i = 0; i < 10; ++i) {
        printf("[%d]%d ", i, array[i]);
    }

    return 0;
}
