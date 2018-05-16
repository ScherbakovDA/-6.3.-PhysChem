//
// Created by denis on 15.05.18.
//

#include "DeltaCapacity.h"
#include "Temperature.h"
#include "Pressure.h"
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
    Pressure p;
    double P = p.P;
    double dCp = dc.dCp;
    double T = t.T;

    dS0 = 86.59;

    dS = dS0 + dCp * logf(T/298) - 8.31 * log(P);
}
#endif //DELTAENTROPY_H
