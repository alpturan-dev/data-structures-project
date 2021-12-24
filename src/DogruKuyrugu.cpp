#include "DogruKuyrugu.hpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

DogruKuyrugu::DogruKuyrugu()
{
    ilk = son = 0;
}
void DogruKuyrugu::ekle(Nokta *nokta)
{
    if (ilk == 0)
    {
        ilk = nokta;
        son = ilk;
    }
    else
    {
        Nokta *yeni = nokta;
        son->sonraki = yeni;
        son = yeni;
    }
}
Nokta *DogruKuyrugu::enKucuktenOncekiDugum()
{
    if (ilk == 0)
        return 0;

    Nokta *gec = ilk;
    Nokta *onceki = 0;
    int enKucuk = gec->uzaklikGetir();

    while (gec->sonraki != 0)
    {
        if (gec->sonraki->uzaklikGetir() < enKucuk)
        {
            enKucuk = gec->sonraki->uzaklikGetir();
            onceki = gec;
        }
        gec = gec->sonraki;
    }
    return onceki;
}
void DogruKuyrugu::enKucukCikar()
{
    Nokta *onceki = enKucuktenOncekiDugum();
    if (onceki)
    {
        if (onceki->sonraki == son)
            son = onceki;
        Nokta *sil = onceki->sonraki;
        onceki->sonraki = sil->sonraki;
        delete sil;
    }
    else
    {
        if (ilk == 0)
            return;
        Nokta *sil = ilk;
        ilk = ilk->sonraki;
        delete sil;
    }
}
int DogruKuyrugu::enKucukGetir()
{
    Nokta *onceki = enKucuktenOncekiDugum();

    if (onceki)
        return onceki->sonraki->uzaklikGetir();
    if (ilk != 0)
        return ilk->uzaklikGetir();
    throw std::out_of_range("Kuyruk Bos");
}
ostream &operator<<(ostream &os, DogruKuyrugu &kuyruk)
{
    for (int i = 0; i < kuyruk.noktaSayisi; i++)
    {
        cout << kuyruk.enKucukGetir() << " ";
        kuyruk.enKucukCikar();
    }

    os << endl;
    return os;
}

int DogruKuyrugu::araUzunluk(Nokta basNokta, Nokta sonNokta)
{
    int ara = sqrt(
        (basNokta.noktaGetirx() - sonNokta.noktaGetirx()) * (basNokta.noktaGetirx() - sonNokta.noktaGetirx()) + (basNokta.noktaGetiry() - sonNokta.noktaGetiry()) * (basNokta.noktaGetiry() - sonNokta.noktaGetiry()) + (basNokta.noktaGetirz() - sonNokta.noktaGetirz()) * (basNokta.noktaGetirz() - sonNokta.noktaGetirz()));
    return ara;
}

int DogruKuyrugu::toplamUzunlukBul(Nokta nokta[], int noktaSayisi)
{
    this->noktaSayisi = noktaSayisi;
    for (int i = 0; i < noktaSayisi - 1; i++)
    {
        toplamUzunluk += araUzunluk(nokta[i], nokta[i + 1]);
    }

    return toplamUzunluk;
}
