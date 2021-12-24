#if !defined(Nokta_hpp)
#define Nokta_hpp
#include <iostream>
using namespace std;

class Nokta
{
public:
    Nokta();
    Nokta(int x, int y, int z);
    int noktaGetirx();
    int noktaGetiry();
    int noktaGetirz();
    int uzaklikGetir();
    Nokta *onceki;
    Nokta *sonraki;

private:
    int x;
    int y;
    int z;
    int uzaklik;
};

#endif