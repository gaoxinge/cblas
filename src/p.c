#include "cblas.h"

void cblas_sswap(const int N, 
                 float *X, 
                 const int incX, 
                 float *Y, 
                 const int incY) {
    float x, y;
    for (int i = 0; i < N; i++) {
        x = (*X);
        y = (*Y);
        *X = y;
        *Y = x;
        X += incX;
        Y += incY;
    }
}

void cblas_scopy(const int N, 
                 const float *X, 
                 const int incX, 
                 float *Y, 
                 const int incY) {
    for (int i = 0; i < N; i++) {
        *Y = *X;
        X += incX;
        Y += incY;
    }
}

void cblas_saxpy(const int N, 
                 const float alpha, 
                 const float *X,
                 const int incX, 
                 float *Y, 
                 const int incY) {
    for (int i = 0; i < N; i++) {
        *Y = *Y + alpha * (*X);
        X += incX;
        Y += incY;
    }
}

void cblas_dswap(const int N, 
                 double *X, 
                 const int incX, 
                 double *Y, 
                 const int incY) {
    double x, y;
    for (int i = 0; i < N; i++) {
        x = (*X);
        y = (*Y);
        *X = y;
        *Y = x;
        X += incX;
        Y += incY;
    }
}

void cblas_dcopy(const int N, 
                 const double *X, 
                 const int incX, 
                 double *Y, 
                 const int incY) {
    for (int i = 0; i < N; i++) {
        *Y = *X;
        X += incX;
        Y += incY;
    }
}

void cblas_daxpy(const int N, 
                 const double alpha, 
                 const double *X,
                 const int incX, 
                 double *Y, 
                 const int incY) {
    for (int i = 0; i < N; i++) {
        *Y = *Y + alpha * (*X);
        X += incX;
        Y += incY;
    }
}

void cblas_cswap(const int N, 
                 void *X, 
                 const int incX, 
                 void *Y, 
                 const int incY) {
    float *_X = X;
    float *_Y = Y;
    float x_re, x_im, y_re, y_im;
    for (int i = 0; i < N; i++) {
        x_re = _X[0];
        x_im = _X[1];
        y_re = _Y[0];
        y_im = _Y[1];
        
        _X[0] = y_re;
        _X[1] = y_im;
        _Y[0] = x_re;
        _Y[1] = x_im;
        
        _X += 2 * incX;
        _Y += 2 * incY;
    }
}

void cblas_ccopy(const int N, 
                 const void *X, 
                 const int incX, 
                 void *Y, 
                 const int incY) {
    const float *_X = X;
    float *_Y = Y;
    for (int i = 0; i < N; i++) {
        _Y[0] = _X[0];
        _Y[1] = _X[1];
        _X += 2 * incX;
        _Y += 2 * incY;
    }
}

void cblas_caxpy(const int N, 
                 const void *alpha, 
                 const void *X,
                 const int incX, 
                 void *Y, 
                 const int incY) {
    const float *_alpha = alpha;
    const float *_X = X;
    float *_Y = Y;
    for (int i = 0; i < N; i++) {
        _Y[0] = _Y[0] + _alpha[0] * _X[0];
        _Y[1] = _Y[1] + _alpha[1] * _X[1];
        _X += 2 * incX;
        _Y += 2 * incY;
    }
}

void cblas_zswap(const int N, 
                 void *X, 
                 const int incX, 
                 void *Y, 
                 const int incY) {
    double *_X = X;
    double *_Y = Y;
    double x_re, x_im, y_re, y_im;
    for (int i = 0; i < N; i++) {
        x_re = _X[0];
        x_im = _X[1];
        y_re = _Y[0];
        y_im = _Y[1];
        
        _X[0] = y_re;
        _X[1] = y_im;
        _Y[0] = x_re;
        _Y[1] = x_im;
        
        _X += 2 * incX;
        _Y += 2 * incY;
    }
}

void cblas_zcopy(const int N, 
                 const void *X, 
                 const int incX, 
                 void *Y, 
                 const int incY) {
    const double *_X = X;
    double *_Y = Y;
    for (int i = 0; i < N; i++) {
        _Y[0] = _X[0];
        _Y[1] = _X[1];
        _X += 2 * incX;
        _Y += 2 * incY;
    }
}

void cblas_zaxpy(const int N, 
                 const void *alpha, 
                 const void *X,
                 const int incX, 
                 void *Y, 
                 const int incY) {
    const double *_alpha = alpha;
    const double *_X = X;
    double *_Y = Y;
    for (int i = 0; i < N; i++) {
        _Y[0] = _Y[0] + _alpha[0] * _X[0];
        _Y[1] = _Y[1] + _alpha[1] * _X[1];
        _X += 2 * incX;
        _Y += 2 * incY;
    }
}