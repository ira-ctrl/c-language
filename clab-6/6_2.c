#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double minimal(double a, double b) {
    if (a < b) {
        return a;
    }
    return b;
}

double minimalAbsElement(double array[], int n) {
    double min = n * 10000;

    for (int i = 0; i < n - 1; ++i) {
        min = minimal(min, minimal(abs(array[i]), abs(array[i + 1])));
    }

    return min;
}

int foundZIndex(double array[], int n){
    int returnedValue = 1;

    for (int i = 0; i < n; ++i) {
        if (array[i] == 0){
            for (int j = i+1; j < n && array[j] != 0; ++j) {
                returnedValue *= array[j];
                i = j;
            }
        }
    }

    return returnedValue;
}

int main() {
    srand((unsigned) time(0));
    double array[10];

    for (int i = 0; i < 10; ++i) {
        array[i] = -100 + rand() % (100 - -100 + 1);
        printf("[%d]%1.f ", i, array[i]);
    }

    double valueZ = foundZIndex(array, 10);
    if ( valueZ == 1 ){
        printf("\nSorry, but zero value not founded in array.");
    } else {
        printf("\nThe result of multiplying all the numbers between the two zeros: %d", foundZIndex(array, 10));
    }
    printf("\nMinimal abs element of the array: %1.f", minimalAbsElement(array, 10));

    return 0;
}
