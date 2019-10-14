#include <stdio.h>
#include "cblas.h"

void test_dot() {
    float X1[] = {1, 1, 1};
    float Y1[] = {2, 2, 2};
    float result1;
    double X2[] = {1, 1, 1};
    double Y2[] = {2, 2, 2};
    double result2;

    result1 = cblas_sdsdot(3, 1, X1, 1, Y1, 1);
    printf("cblas_sdsdot: %f\n", result1);
    result2 = cblas_dsdot(3, X1, 1, Y1, 1);
    printf("cblas_dsdot: %lf\n", result2);
    result1 = cblas_sdot(3, X1, 1, Y1, 1);
    printf("cblas_sdot: %f\n", result1);
    result2 = cblas_ddot(3, X2, 1, Y2, 1);
    printf("cblas_ddot: %lf\n", result2);
}


int main() {
    test_dot();
    return 0;
}
