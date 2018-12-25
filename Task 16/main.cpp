#include <iostream>

#include "complex.h"

int main(int argc, char *argv[]) {

    Complex one;
    Complex two;

    one.real = 10;
    one.imaginary = 3;

    two.real = 5;
    two.imaginary = 1;

    std::cout << "Add: " << std::endl;

    Complex complex = addition(&one, &two);

    std::cout << complex.real << " " << complex.imaginary << std::endl;

    std::cout << std::endl << "Miltiplication: " << std::endl;

    complex = multiplication(&one, &two);

    std::cout << complex.real << " " << complex.imaginary << std::endl << std::endl;

    std::cout << "Module: " << std::endl;
    std::cout << pythagorean_theorem(&one) << std::endl << std::endl;
    std::cout << "Argument: " << std::endl;
    std::cout << number_argument(&one) << std::endl;

    std::cout <<  std::endl << "Conjugate" << std::endl; 
    algebraic_form(conjugate_number(&one));
    
    std::cout << std::endl << "Algebraic, trgonometric and idicative form's:" << std::endl;
    
    algebraic_form(divide(&one, &two));
    trigonometric_form(&one);
    indicative_form(&one);

    return 0;
}