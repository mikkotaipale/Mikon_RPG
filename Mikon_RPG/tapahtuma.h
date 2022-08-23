#pragma once

#include "STLINCLUDE.h"

#include "hahmo.h"
#include "vihollinen.h"
#include "pulmapeli.h"



class Tapahtuma
{
public:
    Tapahtuma();
    virtual ~Tapahtuma();
    void luoTapahtuma(Hahmo &hahmo, dArr<Vihollinen>& viholliset); //tapahtuman luonti

    //Tapahtumat
    void vKohtaaminen(Hahmo &hahmo, dArr<Vihollinen>& viholliset);
    void pulmanRatkaisu(Hahmo &hahmo);

private:
    int tapMaara; //tapahtumien määrä

};

