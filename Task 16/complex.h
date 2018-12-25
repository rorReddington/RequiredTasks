#ifndef COMPLEX_H_INCLUDED
#define COMPLEX_H_INCLUDED

struct Complex {

    float real;
    float imaginary;
};

Complex addition(Complex *one, Complex *two);

Complex multiplication(Complex *one, Complex *two);

Complex divide(Complex *one, Complex *two);

float pythagorean_theorem(Complex *one);

float number_argument(Complex *one);

Complex conjugate_number(Complex *one);

void algebraic_form(Complex one);

void trigonometric_form(Complex *one);

void indicative_form(Complex *one);

#endif // COMPLEX_H_INCLUDED