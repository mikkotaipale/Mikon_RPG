#pragma once
#include "tavara.h"


enum armoriTyyppi { HEAD = 0, CHEST, ARMS, LEGS};

class Armori :
   public Tavara
{
private:
    int tyyppi;
    std::string tyyppiStr;
    int aDefense;

public:
    Armori();
    Armori(int tLevel, int rarity);
    Armori(int tyyppi, int aDefense,
            std::string name, int tLevel,
            int bValue, int sValue, int rarity);
    virtual ~Armori();

    //Virutaaliset F
    virtual Armori* clone() const;

    //F
    std::string toString()const;

    //A
    inline int getDefense()const {return this->aDefense; }
    inline int getType()const {return this->tyyppi; }

    //S
    static dArr<string> names;
    static void initNames();
};


