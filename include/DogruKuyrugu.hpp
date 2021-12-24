#if !defined(DogruKuyrugu_hpp)
#define DogruKuyrugu_hpp
#include "Nokta.hpp"
#include <iostream>
using namespace std;

class DogruKuyrugu
{
public:
    DogruKuyrugu();
    ~DogruKuyrugu();
    void ekle(Nokta *nokta);
    void enKucukCikar();
    int enKucukGetir();
    Nokta *enKucuktenOncekiDugum();
    int araUzunluk(Nokta basNokta, Nokta sonNokta);
    int toplamUzunlukBul(Nokta nokta[], int noktaSayisi);
    friend ostream &operator<<(ostream &os, DogruKuyrugu &kuyruk);
    int toplamUzunluk;
    int noktaSayisi;
    Nokta *ilk;
    Nokta *son;
};

#endif