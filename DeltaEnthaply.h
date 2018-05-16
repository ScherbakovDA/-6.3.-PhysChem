//
// Created by denis on 15.05.18.
//

#include "DeltaCapacity.h"
#include "Temperature.h"

#ifndef DELTAENTHAPLY_H
#define DELTAENTHAPLY_H

class DeltaEnthaply
{
public:
    double dH0;
    double dH;
    DeltaEnthaply();
};

DeltaEnthaply::DeltaEnthaply()
{
    DeltaCapacity dc;
    Temperature t;
    double T = t.T;
    double dCp = dc.dCp;

    dH0 = 282.98;

    dH = dH0 * 1000 + dCp * (T - 298);
}

#endif //DELTAENTHAPLY_H
