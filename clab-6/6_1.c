#include <stdio.h>

double maximalValue(double a, double b){
    if (a > b){
        return a;
    } else {
        return b;
    }
}

int main() {
    double a = 1, b = 2, c = 2;
    double u = (maximalValue(a, a+b)+maximalValue(a, b+c))/(1+maximalValue(a+b*c, b-c));

    printf("u = %f", u);
    return 0;
}
