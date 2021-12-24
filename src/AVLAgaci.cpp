#include "AVLAgaci.hpp"
#include <cmath>
#include <iomanip>
#include <iostream>
#include <queue>
using namespace std;
AVLAgaci::AVLAgaci()
{
    kok = 0;
}
AVLAgaci::~AVLAgaci()
{
}

void AVLAgaci::ekle(int eklenecek, DogruKuyrugu *kuyruk)
{
    kok = ekle(eklenecek, kok, kuyruk);
}

int AVLAgaci::yukseklik()
{
    return yukseklik(kok);
}

void AVLAgaci::postOrder()
{
    postOrder(kok);
}

void AVLAgaci::postOrder(Dugum *aktif)
{
    if (aktif)
    {
        postOrder(aktif->sol);
        postOrder(aktif->sag);
        cout << *(aktif->kuyruk);
    }
}

int AVLAgaci::yukseklik(Dugum *aktifDugum)
{
    if (aktifDugum)
    {
        return 1 + max(yukseklik(aktifDugum->sol), yukseklik(aktifDugum->sag));
    }
    return -1;
}
Dugum *AVLAgaci::ekle(int veri, Dugum *aktifDugum, DogruKuyrugu *kuyruk)
{
    if (aktifDugum == 0)
        return new Dugum(veri, kuyruk);

    else if (aktifDugum->veri < veri)
    {
        aktifDugum->sag = ekle(veri, aktifDugum->sag, kuyruk);
        if (yukseklik(aktifDugum->sag) - yukseklik(aktifDugum->sol) > 1)
        {
            if (veri > aktifDugum->sag->veri)
                aktifDugum = solaDondur(aktifDugum);

            else
            {
                aktifDugum->sag = sagaDondur(aktifDugum->sag);
                aktifDugum = solaDondur(aktifDugum);
            }
        }
    }
    else if (aktifDugum->veri > veri)
    {
        aktifDugum->sol = ekle(veri, aktifDugum->sol, kuyruk);
        if (yukseklik(aktifDugum->sol) - yukseklik(aktifDugum->sag) > 1)
        {

            if (veri < aktifDugum->sol->veri)
                aktifDugum = sagaDondur(aktifDugum);
            else
            {
                aktifDugum->sol = solaDondur(aktifDugum->sol);
                aktifDugum = sagaDondur(aktifDugum);
            }
        }
    }
    return aktifDugum;
}
Dugum *AVLAgaci::solaDondur(Dugum *buyukEbeveyn)
{
    Dugum *sagCocuk = buyukEbeveyn->sag;
    buyukEbeveyn->sag = sagCocuk->sol;
    sagCocuk->sol = buyukEbeveyn;
    return sagCocuk;
}
Dugum *AVLAgaci::sagaDondur(Dugum *buyukEbeveyn)
{
    Dugum *solCocuk = buyukEbeveyn->sol;
    buyukEbeveyn->sol = solCocuk->sag;
    solCocuk->sag = buyukEbeveyn;
    return solCocuk;
}

ostream &operator<<(ostream &os, AVLAgaci &agac)
{
    agac.postOrder();

    return os;
}