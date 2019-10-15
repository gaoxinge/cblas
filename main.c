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

void test_p() {
    float X1[] = {1};
    float Y1[] = {2};

    cblas_sswap(1, X1, 1, Y1, 1);
    printf("cblas_sswap: %f %f\n", X1[0], Y1[0]);
    cblas_scopy(1, X1, 1, Y1, 1);
    printf("cblas_scopy: %f\n", Y1[0]);
    cblas_saxpy(1, 2, X1, 1, Y1, 1);
    printf("cblas_saxpy: %f\n", Y1[0]);
    
    double X2[] = {1};
    double Y2[] = {2};
    
    cblas_dswap(1, X2, 1, Y2, 1);
    printf("cblas_dswap: %lf %lf\n", X2[0], Y2[0]);
    cblas_dcopy(1, X2, 1, Y2, 1);
    printf("cblas_dcopy: %lf\n", Y2[0]);
    cblas_daxpy(1, 2, X2, 1, Y2, 1);
    printf("cblas_daxpy: %lf\n", Y2[0]);
    
    float X3[] = {1, 1};
    float Y3[] = {2, 2};
    float alpha1[] = {1, 2};

    cblas_cswap(1, X3, 1, Y3, 1);
    printf("cblas_cswap: %f %f %f %f\n", X3[0], X3[1], Y3[0], Y3[1]);
    cblas_ccopy(1, X3, 1, Y3, 1);
    printf("cblas_ccopy: %f %f\n", Y3[0], Y3[1]);
    cblas_caxpy(1, alpha1, X3, 1, Y3, 1);
    printf("cblas_caxpy: %f %f\n", Y3[0], Y3[1]);
    
    double X4[] = {1, 1};
    double Y4[] = {2, 2};
    double alpha2[] = {1, 2};

    cblas_zswap(1, X4, 1, Y4, 1);
    printf("cblas_zswap: %lf %lf %lf %lf\n", X4[0], X4[1], Y4[0], Y4[1]);
    cblas_zcopy(1, X4, 1, Y4, 1);
    printf("cblas_zcopy: %lf %lf\n", Y4[0], Y4[1]);
    cblas_zaxpy(1, alpha2, X4, 1, Y4, 1);
    printf("cblas_zaxpy: %lf %lf\n", Y4[0], Y4[1]);
}

int main() {
    test_dot();
    test_dot_sub();
    test_num();
    test_max();
    test_p();
    return 0;
}
