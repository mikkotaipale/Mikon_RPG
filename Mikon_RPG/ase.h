#pragma once
#include "tavara.h"

class Ase :
    public Tavara
{
private:
    int aDmgMin; //aseen minimi damage
    int aDmgMax; //aseen maksimi damage

public:
    Ase();
    Ase(int tLevel, int rarity);
    Ase(int aDmgMin, int aDmgMax,
        std::string name, int tLevel,
        int bValue, int sValue, int rarity);
    virtual ~Ase();

    //Virtuaaliset F
    virtual Ase* clone() const;

    //F
    std::string toString()const;

    //A
    inline int getDmgMin()const {return this->aDmgMin; }
    inline int getDmgMax()const {return this->aDmgMax; }

    //S
    static dArr<std::string> names;
    static void initNames();
};


