#include <stdio.h>

#include <math.h>

 

int main() {

    double A, B;

    scanf("%lf %lf", &A, &B);

    double M = (B - A) / 400;

    double den = 1 + pow(10, M);

    double result = 1 / den;

    printf("%lf\n", result);

}