//
// Created by denis on 15.05.18.
//

#include "DeltaCapacity.h"
#include "DeltaEnthaply.h"
#include "DeltaEntropy.h"

#ifndef GIBBSPOTETIAL_H
#define GIBBSPOTETIAL_H

class GibbsPotetial
{
public:
    double dG;
    GibbsPotetial();
};

GibbsPotetial::GibbsPotetial()
{
    DeltaEnthaply dh;
    DeltaEntropy ds;
    Temperature t;
    double T = t.T;
    double dS = ds.dS;
    double dH = dh.dH;

    dG = dH - T * dS;

    /*std::cout << "dH = " << dH << std::endl;
    std::cout << "dS = " << dS << std::endl;*/
}

#endif //GIBBSPOTETIAL_H
