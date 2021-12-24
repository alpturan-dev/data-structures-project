#include "Nokta.hpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

Nokta::Nokta(int x, int y, int z)
{
    this->x = x;
    this->y = y;
    this->z = z;
    uzaklik = sqrt((x * x) + (y * y) + (z * z));
}

int Nokta::noktaGetirx()
{
    return this->x;
}
int Nokta::noktaGetiry()
{
    return this->y;
}
int Nokta::noktaGetirz()
{
    return this->z;
}
int Nokta::uzaklikGetir()
{
    return this->uzaklik;
}
Nokta::Nokta()
{
}