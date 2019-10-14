#include <math.h>
#include "cblas.h"

/* 2-norm */
float cblas_snrm2(const int N, 
                  const float *X, 
                  const int incX) {
    float result = 0;
    for (int i = 0; i < N; i++) {
        result += (*X) * (*X);
        X += incX;
    }
    return sqrt(result);
}

/* abs sum */
float cblas_sasum(const int N, 
                  const float *X, 
                  const int incX) {
    float result = 0;
    for (int i = 0; i < N; i++) {
        result += abs(*X);
        X += incX;
    }
    return result;
}

/* 2-norm */
double cblas_dnrm2(const int N, 
                   const double *X, 
                   const int incX) {
    double result = 0;
    for (int i = 0; i < N; i++) {
        result += (*X) * (*X);
        X += incX;
    }
    return sqrt(result);
}

/* abs sum */
double cblas_dasum(const int N, 
                   const double *X, 
                   const int incX) {
    double result = 0;
    for (int i = 0; i < N; i++) {
        result += abs(*X);
        X += incX;
    }
    return result;
}

/* 2-norm */
float cblas_scnrm2(const int N, 
                   const void *X, 
                   const int incX) {
    const float *_X = X;
    float result = 0;
    for (int i = 0; i < N; i++) {
        result += (_X[0]) * (_X[0]);
        result += (_X[1]) * (_X[1]);
        _X += 2 * incX;
    }
    return sqrt(result);
}

/* abs sum */
float cblas_scasum(const int N, 
                   const void *X, 
                   const int incX) {
    const float *_X = X;
    float result = 0;
    for (int i = 0; i < N; i++) {
        result += abs(_X[0]);
        result += abs(_X[1]);
        _X += 2 * incX;
    }
    return result;
}

/* 2-norm */
double cblas_dznrm2(const int N, 
                    const void *X, 
                    const int incX) {
    const double *_X = X;
    double result = 0;
    for (int i = 0; i < N; i++) {
        result += (_X[0]) * (_X[0]);
        result += (_X[1]) * (_X[1]);
        _X += 2 * incX;
    }
    return sqrt(result);
}

/* abs sum */
double cblas_dzasum(const int N, 
                    const void *X, 
                    const int incX) {
    const double *_X = X;
    double result = 0;
    for (int i = 0; i < N; i++) {
        result += abs(_X[0]);
        result += abs(_X[1]);
        _X += 2 * incX;
    }
    return result;
}