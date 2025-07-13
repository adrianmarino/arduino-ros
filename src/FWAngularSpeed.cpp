#include "FWAngularSpeed.h"

FWAngularSpeed::FWAngularSpeed() : fl(0), fr(0), bl(0), br(0) {}

void FWAngularSpeed::updateFrom(float fl, float fr, float bl, float br)
{
    this->fl = fl;
    this->fr = fr;
    this->bl = bl;
    this->br = br;
}

float FWAngularSpeed::getFlWInRad() const { return fl; }
float FWAngularSpeed::getFrWInRad() const { return fr; }
float FWAngularSpeed::getBlWInRad() const { return bl; }
float FWAngularSpeed::getBrWInRad() const { return br; }