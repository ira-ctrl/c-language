#include <stdio.h>
#include <stdlib.h>

int getMinimal(a, b) {
    if (a < b) {
        return a;
    }
    return b;
}

int *getMinimalElementInformation(int **array, int n) {
    int minimal[4] = { 0, 0, 0 }; //value, coords: x, y
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            minimal[ 0 ] = getMinimal(minimal[0] , getMinimal(&array[i][j], &array[i][j+1]));
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n-1; ++j) {
            if (minimal[0] == &array[i][j]){
                minimal[1] = i;
                minimal[2] = j;
            }
        }
    }

    return minimal;
}


int main() {
    const int n = 3;
    int array[3][3] = {{2,  4,   -6},
                       {-6, -11, 6},
                       {2,  6,   0}};
    int  * result = getMinimalElementInformation(array, n);

    printf("\nMinimal element value = %d, address: %d; x = %d, y = %d.", result[0], &array[result[1]][result[2]], result[1], result[2]);
    return 0;
}
