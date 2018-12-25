#include <iostream>
#include <cmath>

#include "complex.h"

Complex addition(Complex *one, Complex *two) {

    Complex complex;

    complex.real = one->real + two->real;
    complex.imaginary = one->imaginary + two->imaginary;
    
    return complex;
}

Complex multiplication(Complex *one, Complex *two) {

    Complex complex;

    complex.real = one->real * two->real - one->imaginary * two->imaginary;
    complex.imaginary = one->real * two->imaginary + two->real * one->imaginary;
    
    return complex;
}

Complex divide(Complex *one, Complex *two) {

    Complex complex;

    complex.real = (one->real*two->real + one->imaginary * two->imaginary)/(pythagorean_theorem(two)*pythagorean_theorem(two));
    complex.imaginary = (two->real*one->imaginary - two->imaginary * one->real)/(pythagorean_theorem(two)*pythagorean_theorem(two));

    return complex;
}

float pythagorean_theorem(Complex *one) {

    return std::sqrt(one->real*one->real+one->imaginary*one->imaginary);
}

float number_argument(Complex *one) {

    return std::atan(one->imaginary/one->real);    
}

Complex conjugate_number(Complex *one) {

    Complex complex;

    complex.real = one->real;
    complex.imaginary = one->imaginary*-1;

    return complex;
}

void algebraic_form(Complex one) {

    std::cout << one.real << " + i(" << one.imaginary << ")" << std::endl;
}

void trigonometric_form(Complex *one) {

    std::cout << pythagorean_theorem(one)
              << "*cos" << (one->real) / std::sqrt(one->real*one->real + one->imaginary*one->imaginary)
              << "+i(sin" << (one->imaginary) / std::sqrt(one->real*one->real + one->imaginary*one->imaginary)
              << ")" << std::endl;
}

void indicative_form(Complex *one) {

    std::cout << pythagorean_theorem(one) <<"*e^" << one->real << "+i(" << one->imaginary << ")" << std::endl;
}
