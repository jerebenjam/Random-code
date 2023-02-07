#include "kerrostalo.h"

Kerrostalo::Kerrostalo()
{
    cout<<"kerrostalo luotu"<<endl;
    eka.maaritaAsunnot();
    toka.maaritaAsunnot();
    kolmas.maaritaAsunnot();
    //laskeKulutus(1);
}

Kerrostalo::~Kerrostalo()
{

}

double Kerrostalo::laskeKulutus(double hinta)
{
    double kulutus = eka.laskeKulutus(hinta)+toka.laskeKulutus(hinta)+kolmas.laskeKulutus(hinta);
    cout<<"Kerrostalon kulutus = "<<kulutus<<endl;
}
