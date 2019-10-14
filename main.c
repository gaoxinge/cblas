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

void test_dot_sub() {
    float X1[] = {1, 1, 1, 1};
    float Y1[] = {2, 2, 2, 2};
    float result1[] = {0, 0};
    double X2[] = {1, 1, 1, 1};
    double Y2[] = {2, 2, 2, 2};
    double result2[] = {0, 0};
    
    cblas_cdotu_sub(2, X1, 1, Y1, 1, result1);
    printf("cblas_cdotu_sub: %f %f\n", result1[0], result1[1]);
    cblas_cdotc_sub(2, X1, 1, Y1, 1, result1);
    printf("cblas_cdotc_sub: %f %f\n", result1[0], result1[1]);
    cblas_zdotu_sub(2, X2, 1, Y2, 1, result2);
    printf("cblas_zdotu_sub: %lf %lf\n", result2[0], result2[1]);
    cblas_zdotc_sub(2, X2, 1, Y2, 1, result2);
    printf("cblas_zdotc_sub: %lf %lf\n", result2[0], result2[1]);
}

void test_num() {
    float X1[] = {1, 1, 1, 1};
    double X2[] = {1, 1, 1, 1};
    
    printf("cblas_snrm2: %f\n", cblas_snrm2(4, X1, 1));
    printf("cblas_sasum: %f\n", cblas_sasum(4, X1, 1));
    printf("cblas_dnrm2: %f\n", cblas_dnrm2(4, X2, 1));
    printf("cblas_dasum: %f\n", cblas_dasum(4, X2, 1));
    printf("cblas_scnrm2: %f\n", cblas_scnrm2(2, X1, 1));
    printf("cblas_scasum: %f\n", cblas_scasum(2, X1, 1));
    printf("cblas_dznrm2: %f\n", cblas_dznrm2(2, X2, 1));
    printf("cblas_dzasum: %f\n", cblas_dzasum(2, X2, 1));
}

void test_max() {
    float X1[] = {1, 3, 2, 3};
    double X2[] = {1, 3, 2, 3};
    
    printf("cblas_isamax: %I64d\n", cblas_isamax(4, X1, 1));
    printf("cblas_idamax: %I64d\n", cblas_idamax(4, X2, 1));
    printf("cblas_icamax: %I64d\n", cblas_icamax(2, X1, 1));
    printf("cblas_izamax: %I64d\n", cblas_izamax(2, X2, 1));
}

int main() {
    test_dot();
    test_dot_sub();
    test_num();
    test_max();
    return 0;
}
