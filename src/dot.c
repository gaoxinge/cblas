#include "cblas.h"

/* alpha + X^t * Y */
float cblas_sdsdot(const int N,
                   const float alpha,
                   const float *X,
                   const int incX,
                   const float *Y,
                   const int incY) {
    double result = alpha;
    double x, y;
    for (int i = 0; i < N; i++) {
        x = *X;
        y = *Y;
        result += x * y;
        X += incX;
        Y += incY;
    }
    return result; 
}

/* X^t + Y */
double cblas_dsdot(const int N,
                   const float *X,
                   const int incX,
                   const float *Y,
                   const int incY) {
    double result = 0;
    double x, y;
    for (int i = 0; i < N; i++) {
        x = *X;
        y = *Y;
        result += x * y;
        X += incX;
        Y += incY;
    }
    return result;
}

/* X^t + Y */
float cblas_sdot(const int N,
                 const float *X,
                 const int incX,
                 const float *Y,
                 const int incY) {
    double result = 0;
    for (int i = 0; i < N; i++) {
        result += (*X) * (*Y);
        X += incX;
        Y += incY;
    }
    return result;
}

/* X^t + Y */
double cblas_ddot(const int N,
                  const double *X,
                  const int incX,
                  const double *Y,
                  const int incY) {
    double result = 0;
    for (int i = 0; i < N; i++) {
        result += (*X) * (*Y);
        X += incX;
        Y += incY;
    }
    return result;
}
