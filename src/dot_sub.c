#include "cblas.h"

/* X^t + Y */
void cblas_cdotu_sub(const int N,
                     const void *X,
                     const int incX,
                     const void *Y,
                     const int incY,
                     void *dotu) {
    const float *_X = X, *_Y = Y;
    float re = 0, im = 0;
    float x_re, x_im, y_re, y_im;
    for (int i = 0; i < N; i++) {
        x_re = _X[0];
        x_im = _X[1];
        y_re = _Y[0];
        y_im = _Y[1];
        re += x_re * y_re - x_im * y_im;
        im += x_re * y_im + x_im * y_re;
        _X += 2 * incX;
        _Y += 2 * incY;
    }
    
    float *_dotu = dotu;
    _dotu[0] = re;
    _dotu[1] = im;
}

/* X^h + Y */
void cblas_cdotc_sub(const int N,
                     const void *X,
                     const int incX,
                     const void *Y,
                     const int incY,
                     void *dotc) {
    const float *_X = X, *_Y = Y;
    float re = 0, im = 0;
    float x_re, x_im, y_re, y_im;
    for (int i = 0; i < N; i++) {
        x_re = _X[0];
        x_im = _X[1];
        y_re = _Y[0];
        y_im = _Y[1];
        re += x_re * y_re + x_im * y_im;
        im += x_re * y_im - x_im * y_re;
        _X += 2 * incX;
        _Y += 2 * incY;
    }

    float *_dotc = dotc;
    _dotc[0] = re;
    _dotc[1] = im;
}

/* X^t + Y */
void cblas_zdotu_sub(const int N,
                     const void *X,
                     const int incX,
                     const void *Y,
                     const int incY,
                     void *dotu) {
    const double *_X = X, *_Y = Y;
    double re = 0, im = 0;
    double x_re, x_im, y_re, y_im;
    for (int i = 0; i < N; i++) {
        x_re = _X[0];
        x_im = _X[1];
        y_re = _Y[0];
        y_im = _Y[1];
        re += x_re * y_re - x_im * y_im;
        im += x_re * y_im + x_im * y_re;
        _X += 2 * incX;
        _Y += 2 * incY;
    }

    double *_dotu = dotu;
    _dotu[0] = re;
    _dotu[1] = im;
}

/* X^h + Y */
void cblas_zdotc_sub(const int N,
                     const void *X,
                     const int incX,
                     const void *Y,
                     const int incY,
                     void *dotc) {
    const double *_X = X, *_Y = Y;
    double re = 0, im = 0;
    double x_re, x_im, y_re, y_im;
    for (int i = 0; i < N; i++) {
        x_re = _X[0];
        x_im = _X[1];
        y_re = _Y[0];
        y_im = _Y[1];
        re += x_re * y_re + x_im * y_im;
        im += x_re * y_im - x_im * y_re;
        _X += 2 * incX;
        _Y += 2 * incY;
    }

    double *_dotc = dotc;
    _dotc[0] = re;
    _dotc[1] = im;
}