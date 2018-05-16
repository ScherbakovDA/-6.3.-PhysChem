//
// Created by denis on 16.05.18.
//

#include "Temperature.h"
#include "GibbsPotetial.h"
#include <cmath>

#ifndef EXPONATION_H
#define EXPONATION_H

class Exponation
{
public:
    double exponation;
    Exponation();
};

Exponation::Exponation()
{
    GibbsPotetial dg;
    Temperature t;
    double dG = dg.dG;
    double T = t.T;

    exponation = exp(-(2 * dG)/(8.31 * T));

    /*std::cout << "dG = " << dG << std::endl;
    std::cout << "T = " << T << std::endl;
    std::cout << "exp = " << exponation << std::endl;
    std::cout << std::endl;*/


}
#endif //EXPOTATION_H
