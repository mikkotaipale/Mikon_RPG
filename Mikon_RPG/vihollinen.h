#pragma once

#include"STLINCLUDE.h"

class Vihollinen
{
public:
    Vihollinen(int vLevel = 0);
    virtual ~Vihollinen();

    inline bool isAlive() { return this->vHp > 0; }
    std::string getAsString()const;
    void takeDmg(int dmg); //vihollinen ottaa vahinkoa

    inline int getLevel()const { return this->vLevel; }
    inline int getDmgMin()const { return this->dmgMin; }
    inline int getDmgMax()const { return this->dmgMax; }
    inline int getDmg()const { return rand() % this->dmgMax + this->dmgMin; } //vihollinen tekee vahinkoa
    inline int getExp()const { return this->vLevel * 100; } //
    inline int getHp()const { return this->vHp; }
    inline int getHpMax()const { return this->vHpMax; }
    inline int getDefense()const { return this->vDefense; }
    inline int getTarkkuus()const { return this->vTarkkuus; }



private:
    int vLevel;
    int vHp;
    int vHpMax;
    int dmgMin;
    int dmgMax;
    float dropChance;
    int vDefense;
    int vTarkkuus;
};

