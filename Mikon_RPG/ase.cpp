#include "ase.h"

dArr<string> Ase::names;

void Ase::initNames()
{
    Ase::names.push("Voiveitsi");
    Ase::names.push("Tikari");
    Ase::names.push("Miekka");
    Ase::names.push("Vasara");
    Ase::names.push("Nyrkkirauta");
    Ase::names.push("Katana");
    Ase::names.push("Sapeli");
}

Ase::Ase()
    :Tavara()
{
    this->aDmgMax = 0;
    this->aDmgMin = 0;
}

Ase::Ase(int tLevel, int rarity)
    :Tavara(tLevel, rarity)
{
        this->aDmgMax = rand() % (tLevel * (rarity+1));
        this->aDmgMax += (rarity+1) * 5;
    this->setName(Ase::names[rand() % Ase::names.size()]);

        if (rarity == 4)
            this->aDmgMax += tLevel * 5;
        else if (rarity == 5)
            this->aDmgMax += tLevel * 10;

        this->aDmgMin = this->aDmgMax / 2;
}


Ase::Ase(int aDmgMin, int aDmgMax, std::string name, int tLevel, int bValue, int sValue, int rarity)
    : Tavara(name, tLevel, bValue, sValue, rarity)
{
    this->aDmgMin = aDmgMin;
    this->aDmgMax = aDmgMax;
}

Ase::~Ase()
{

}

Ase* Ase::clone()const
{
    return new Ase(*this);
}

std::string Ase::toString()const
{
    std::string str =
            this->getName()
            + " | Lvl "
            + std::to_string(this->getLevel())
            + " | Rarity "
            + std::to_string(this->getRarity())
            + " | Damage: "
            + std::to_string(this->aDmgMin)
            + " - "
            + std::to_string(this->aDmgMax);
            + " |Arvo: "
            + std::to_string(this->getsValue());


    return str;
}
