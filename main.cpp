#include <iostream>
#include "CubicEquation.h"


int main() {

    CubicEquation equation;

    equation.SolveEquation();

    double stingDiss;

    if(equation.root1.imag() == 0)
    {
        if(equation.root1.real() >=0 && equation.root1.real() <= 1)
            stingDiss = equation.root1.real();
    }

    else if(equation.root2.imag() == 0)
    {
        if(equation.root2.real() >=0 && equation.root2.real() <= 1)
            stingDiss = equation.root2.real();
    }

    else if(equation.root3.imag() == 0)
    {
        if(equation.root3.real() >=0 && equation.root3.real() <= 1)
            stingDiss = equation.root3.real();
    }

    std::cout << "alpha = " << stingDiss << std::endl;

    /*std::cout << "root1 = " << equation.root1 << std::endl;
    std::cout << "root2 = " << equation.root2 << std::endl;
    std::cout << "root3 = " << equation.root3 << std::endl;*/


    return 0;
}