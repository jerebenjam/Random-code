#ifndef KATUTASO_H
#define KATUTASO_H
#include "asunto.h"
#include "kerros.h"
#include <iostream>
using namespace std;


class Katutaso:public Kerros
{
public:
    Katutaso();
    ~Katutaso();
    virtual void maaritaAsunnot() override;
    virtual double laskeKulutus(double) override;
    Asunto as1;
    Asunto as2;
};

#endif // KATUTASO_H
