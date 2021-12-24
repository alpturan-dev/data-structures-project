#ifndef AVLAgaci_hpp
#define AVLAgaci_hpp
#include <iostream>
#include "Dugum.hpp"
#include "DogruKuyrugu.hpp"
using namespace std;

class AVLAgaci
{
public:
    AVLAgaci();

    ~AVLAgaci();

    void ekle(int veri, DogruKuyrugu *kuyruk);

    friend ostream &operator<<(ostream &os, AVLAgaci &kuyruk);
    int yukseklik();

    void preOrder();
    void postOrder();

private:
    Dugum *solaDondur(Dugum *dugum);
    Dugum *sagaDondur(Dugum *dugum);

    void postOrder(Dugum *index);

    int yukseklik(Dugum *aktifDugum);
    Dugum *ekle(int veri, Dugum *aktifDugum, DogruKuyrugu *kuyruk);

    Dugum *kok;
};
//diger fonksiyonlar eklenecek
#endif