#pragma once

#include "STLINCLUDE.h"

using namespace std;

class Tavara
{
private:
    std::string name;
    int sValue; //tavaran myyntihinta
    int bValue; //tavaran ostohinta
    int rarity; //tavaran harvinaisuus
    int tLevel; //tavaran taso

public:
    Tavara();
    Tavara(int tLevel, int rarity);
    Tavara(std::string name,
           int tLevel,
           int bValue,
           int sValue,
           int rarity);
    virtual ~Tavara();

    inline std::string debugPrint() const {return this->name; }

    virtual Tavara* clone()const = 0;
    virtual string toString()const = 0;

    //A
    inline const std::string& getName() const{ return this->name; }
    inline const int& getLevel() const{ return this->tLevel; }
    inline const int& getbValue() const{ return this->bValue; }
    inline const int& getsValue() const{ return this->sValue; }
    inline const int& getRarity() const{ return this->rarity; }


    //M
    inline void setName(string name) { this->name = name; }


    //S
    //static dArr<string> names;
    //static void initNames();

};

enum rarity
{
    PERUS = 0,
    PAREMPI,
    HARVINAINEN,
    EEPPINEN,
    LEGENDAARINEN,
    MYYTTINEN
};
