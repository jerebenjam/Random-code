#include "asunto.h"

Asunto::Asunto()
{
    cout<<"asunto luotu"<<endl;
}

Asunto::~Asunto()
{

}

void Asunto::maarita(int asukkaita, int neliot)
{
    cout<<"Asunto maaritetty asukkaita = "<<asukkaita<<" nelioita = "<<neliot<<endl;
}

double Asunto::laskeKulutus(double hinta)
{
    double kulutus = hinta*asukasMaara*neliot;
    return kulutus;
    //cout<<"asunnon kulutus, kun hinta = 1 on "<<kulutus<<endl;
}
