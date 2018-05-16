//
// Created by denis on 16.05.18.
//

#include <complex>
#include "Exponation.h"
#include "Temperature.h"
#include "Pressure.h"
#include "math.h"
#include <iostream>

#ifndef CUBICEQUATION_H
#define CUBICEQUATION_H

double const pi = 3.14159;

class CubicEquation
{
public:
    std::complex<double> root1;
    std::complex<double> root2;
    std::complex<double> root3;
    double a;
    double b;
    double c;
    double d;
    CubicEquation();
    void SolveEquation();
    double signum(double val);
};

void CubicEquation::SolveEquation()
{
    double R = (2 *pow(a,3) - 9 * a*b + 27 *c)/54.0;
    double Q = (pow(a,2) - 3 * b)/9.0;
    double S = pow(Q,3) - pow(R,2);
    double fi;

    /*std::cout << "R = " << R << std::endl;
    std::cout << "Q = " << Q << std::endl;
    std::cout << "S = " << S << std::endl;
    std::cout<<std::endl;*/

    if(S > 0)
    {
        fi = acos(R/pow(Q,0.3333))/3;

        root1.real(-2 *pow(Q,0.5)*cos(fi) - a/3);
        root2.real(-2 *pow(Q,0.5)*cos(fi + 2*pi/3) - a/3);
        root3.real(-2 *pow(Q,0.5)*cos(fi - 2*pi/3) - a/3);
    }
    else if(S<0)
    {
        if(Q>0)
        {
            fi =log(fabs(R)/pow(Q,1.5) + pow(pow(fabs(R)/pow(Q,1.5),2) - 1, 0.5))/3;

            root1.real((-2) *(pow(Q,0.5)*signum(R)*cosh(fi)) - a/3);
            root2.real(pow(Q,0.5)*signum(R)*cosh(fi) - a/3);
            root3.real(pow(Q,0.5)*signum(R)*cosh(fi) - a/3);
            root2.imag(pow(3,0.5)* pow(Q,0.5)*sinh(fi));
            root3.imag(pow(3,0.5)* pow(Q,0.5)*sinh(fi));

        }
        else if(Q<0)
        {
            fi =log(fabs(R)/pow(fabs(Q),1.5) + pow(pow(fabs(R)/pow(fabs(Q),1.5),2) +1, 0.5))/3;

            root1.real(-2 *pow(fabs(Q),0.5)*signum(R)*sinh(fi) - a/3);
            root2.real(pow(fabs(Q),0.5)*signum(R)*sinh(fi) - a/3);
            root3.real(pow(fabs(Q),0.5)*signum(R)*sinh(fi) - a/3);
            root2.imag(pow(3,0.5)* pow(fabs(Q),0.5)*cosh(fi));
            root3.imag(-pow(3,0.5)* pow(fabs(Q),0.5)*cosh(fi));
        }
        else if(Q=0)
        {
            double re1 = root1.real();

            root1.real(-pow(c - pow(a,3)/27,0.3333) - a/3);
            root2.real(-(a + root1.real())/2);
            root3.real(-(a + root1.real())/2);
            root2.imag(0.5 * pow(fabs((a- 3 * re1)*(a + re1) - 4 * b),0.5));
            root3.imag(-0.5 * pow(fabs((a- 3 * re1)*(a + re1) - 4 * b),0.5));
        }
    }
    else if(S = 0)
    {
        root1.real(- 2 * signum(R) * pow(R,0.5) - a/3);
        root2.real(signum(R) * pow(Q,0.5) - a/3);
        root3.real(signum(R) * pow(Q,0.5) - a/3);
    }

}

double CubicEquation::signum(double val)
{
    return (val*(val > 0) - (val < 0));
}

CubicEquation::CubicEquation()
{
    Exponation e;
    Pressure p;
    double P = p.P;
    double exp = e.exponation;
    a = 0;
    b = (3 * exp)/(P - exp);
    c = -(2 * exp)/(P - exp);
    std::complex<double > root1(0,0);
    std::complex<double > root2(0,0);
    std::complex<double > root3(0,0);

    std::cout << "P = " << P << std::endl;
    std::cout << std::endl;
}
#endif //CUBICEQUATION_H
