#include "katutaso.h"

Katutaso::Katutaso()
{
    cout<<"Katutaso luotu"<<endl;
}

Katutaso::~Katutaso()
{

}

void Katutaso::maaritaAsunnot()
{
    cout<<"Maaritetaan 2 kpl katutason asuntoja"<<endl;
    as1.maarita(as1.asukasMaara,as1.neliot);
    as2.maarita(as2.asukasMaara,as2.neliot);
    cout<<"Maaritetaan katutason kerrokselta perittyja asuntoja"<<endl;
    cout<<"Maaritetaan 4 kpl kerroksen asuntoja"<<endl;
    as1.maarita(as1.asukasMaara,as1.neliot);
    as2.maarita(as2.asukasMaara,as2.neliot);
    as3.maarita(as3.asukasMaara,as3.neliot);
    as4.maarita(as4.asukasMaara,as4.neliot);
}

double Katutaso::laskeKulutus(double hinta)
{
    double kulutusKatutaso = as1.laskeKulutus(hinta)+as2.laskeKulutus(hinta);
    double kulutusKerros = as1.laskeKulutus(hinta)+as2.laskeKulutus(hinta)+as3.laskeKulutus(hinta)+as4.laskeKulutus(hinta);
    double kulutus = kulutusKatutaso+kulutusKerros;
    return kulutus;
    //cout<<"Katutason ja perityn kerroksen kulutus, kun hinta = 1 on "<<kulutus<<endl;
}
