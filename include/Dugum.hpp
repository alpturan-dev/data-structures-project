#ifndef Dugum_hpp
#define Dugum_hpp
#include "DogruKuyrugu.hpp"
class Dugum
{
public:
    Dugum(int veri, DogruKuyrugu *kuyruk);
    DogruKuyrugu *kuyruk;
    int veri;
    Dugum *sol;
    Dugum *sag;
};

#endif