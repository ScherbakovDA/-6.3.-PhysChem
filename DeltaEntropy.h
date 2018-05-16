//
// Created by denis on 15.05.18.
//

#include "DeltaCapacity.h"
#include "Temperature.h"
#include <cmath>

#ifndef DELTAENTROPY_H
#define DELTAENTROPY_H

class DeltaEntropy
{
public:
    double dS0;
    double dS;
    DeltaEntropy();
};

DeltaEntropy::DeltaEntropy()
{
    DeltaCapacity dc;
    Temperature t;
    double dCp = dc.dCp;
    double T = t.T;

    dS0 = 86.59;

    dS = dS0 + dCp * logf(T/298);
}
#endif //DELTAENTROPY_H
