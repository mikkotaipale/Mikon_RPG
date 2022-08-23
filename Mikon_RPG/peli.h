#pragma once

#include "funktiot.h"
#include "tapahtuma.h"
#include "STLINCLUDE.h"

using namespace std;

class Peli
{
public:
    Peli();
    virtual ~Peli();

    //O

    //funktiot
    void initGame();
    void mainMenu();
    void teeUusiHahmo();
    void levelUpHahmo();
    //void luetteloEquip();
    void tallennaHahmo();
    void lataaHahmo();
    void valitseHahmo();
    void Seikkaile();
    void Lepo();

    //A
    inline bool getPlaying() const { return this->playing; }

    //---

private:
    int valinta;
    bool playing;

    //Hahmoon liittyvät
    int aktiivinenHahmo;
    std::vector<Hahmo> hahmot;
    std::string fileName;

    //Vihut
    dArr<Vihollinen> viholliset;
};


