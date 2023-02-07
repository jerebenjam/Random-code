#include "kerros.h"

Kerros::Kerros()
{
    cout<<"Kerros luotu"<<endl;
}

Kerros::~Kerros()
{

}

void Kerros::maaritaAsunnot()
{
    cout<<"Maaritetaan 4 kpl kerroksen asuntoja"<<endl;
    as1.maarita(as1.asukasMaara,as1.neliot);
    as2.maarita(as2.asukasMaara,as2.neliot);
    as3.maarita(as3.asukasMaara,as3.neliot);
    as4.maarita(as4.asukasMaara,as4.neliot);
}

double Kerros::laskeKulutus(double hinta)
{
    double kulutus = as1.laskeKulutus(hinta)+as2.laskeKulutus(hinta)+as3.laskeKulutus(hinta)+as4.laskeKulutus(hinta);
    return kulutus;
    //cout<<"Kerroksen kulutus, kun hinta = 1 on "<<kulutus<<endl;
}
