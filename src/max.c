#include <math.h>
#include "cblas.h"

CBLAS_INDEX cblas_isamax(const int N, 
                         const float *X, 
                         const int incX) {
    int imax = 0;
    float xmax = 0;
    float x;
    for (int i = 0; i < N; i++) {
        x = abs(*X);
        if (x > xmax) {
            imax = i;
            xmax = x;
        }
        X += incX;
    }
    return imax;
}

CBLAS_INDEX cblas_idamax(const int N, 
                         const double *X, 
                         const int incX) {
    int imax = 0;
    double xmax = 0;
    double x;
    for (int i = 0; i < N; i++) {
        x = abs(*X);
        if (x > xmax) {
            imax = i;
            xmax = x;
        }
        X += incX;
    }
    return imax;
}

CBLAS_INDEX cblas_icamax(const int N, 
                         const void *X, 
                         const int incX) {
    const float *_X = X;
    int imax = 0;
    float xmax = 0;
    float x;
    for (int i = 0; i < N; i++) {
        x = abs(_X[0]) + abs(_X[1]);
        if (x > xmax) {
            imax = i;
            xmax = x;
        }
        _X += 2 * incX;
    }
    return imax;
}

CBLAS_INDEX cblas_izamax(const int N, 
                         const void *X, 
                         const int incX) {
    const double *_X = X;
    int imax = 0;
    double xmax = 0;
    double x;
    for (int i = 0; i < N; i++) {
        x = abs(_X[0]) + abs(_X[1]);
        if (x > xmax) {
            imax = i;
            xmax = x;
        }
        _X += 2 * incX;
    }
    return imax;
}