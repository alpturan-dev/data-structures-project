#include <iostream>
#include "Nokta.hpp"
#include "DogruKuyrugu.hpp"
#include "AVLAgaci.hpp"
#include "Dugum.hpp"
using namespace std;

int main()
{
    AVLAgaci *agac = new AVLAgaci();
    DogruKuyrugu *d = new DogruKuyrugu();
    Nokta *nokta[4];
    nokta[0] = new Nokta(11, 95, 76);
    nokta[1] = new Nokta(88, 41, 73);
    nokta[2] = new Nokta(96, 73, 16);
    nokta[3] = new Nokta(28, 47, 78);
    d->ekle(nokta[0]);
    d->ekle(nokta[1]);
    d->ekle(nokta[2]);
    d->ekle(nokta[3]);
    cout << "d nin toplam uzunlugu" << d->toplamUzunlukBul(*(nokta), 4) << endl;
    agac->ekle(d->toplamUzunlukBul(*(nokta), 4), d);
    //cout << d->toplamUzunlukBul(*(nokta), 2);
    DogruKuyrugu *z = new DogruKuyrugu();
    Nokta *nokta2[4];
    nokta2[0] = new Nokta(69, 95, 26);
    nokta2[1] = new Nokta(23, 47, 55);
    nokta2[2] = new Nokta(9, 23, 94);
    nokta2[3] = new Nokta(63, 99, 25);
    z->ekle(nokta2[0]);
    z->ekle(nokta2[1]);
    z->ekle(nokta2[2]);
    z->ekle(nokta2[3]);
    agac->ekle(z->toplamUzunlukBul(*(nokta2), 4), z);
    cout << "z nin toplam uzunlugu" << z->toplamUzunlukBul(*(nokta2), 4) << endl;

    DogruKuyrugu *f = new DogruKuyrugu();
    Nokta *nokta3[4];
    nokta3[0] = new Nokta(65, 4, 11);
    nokta3[1] = new Nokta(19, 93, 31);
    nokta3[2] = new Nokta(31, 79, 93);
    nokta3[3] = new Nokta(12, 15, 47);
    f->ekle(nokta3[0]);
    f->ekle(nokta3[1]);
    f->ekle(nokta3[2]);
    f->ekle(nokta3[3]);
    agac->ekle(f->toplamUzunlukBul(*(nokta3), 4), f);
    cout << "f nin toplam uzunlugu" << f->toplamUzunlukBul(*(nokta3), 4) << endl;

    DogruKuyrugu *k = new DogruKuyrugu();
    Nokta *nokta4[5];
    nokta4[0] = new Nokta(65, 4, 11);
    nokta4[1] = new Nokta(19, 93, 31);
    nokta4[2] = new Nokta(31, 79, 93);
    nokta4[3] = new Nokta(12, 15, 47);
    nokta4[4] = new Nokta(1, 15, 47);
    k->ekle(nokta4[0]);
    k->ekle(nokta4[1]);
    k->ekle(nokta4[2]);
    k->ekle(nokta4[3]);
    k->ekle(nokta4[4]);
    agac->ekle(k->toplamUzunlukBul(*(nokta4), 5), k);
    cout << "k nin toplam uzunlugu" << k->toplamUzunlukBul(*(nokta4), 5) << endl;

    cout << *(agac);
    //HER SEY BITTI, MAIN.CPP ayarla.
    // Agaca ekleme yontemi bulmaca.
}