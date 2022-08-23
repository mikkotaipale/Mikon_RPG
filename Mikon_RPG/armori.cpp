#include "armori.h"

dArr<std::string> Armori::names;

void Armori::initNames()
{
    Armori::names.push("Nahkahousut");
    Armori::names.push("Nahkapaita");
    Armori::names.push("Nahkalakki");
    Armori::names.push("Nahkahanskat");
    Armori::names.push("Rautasuoja");
    Armori::names.push("Kapteenin Hattu");
    Armori::names.push("Rautahanskat");
}

Armori::Armori()
      :Tavara()
{
    this->aDefense = 0;
}

Armori::Armori(int tLevel, int rarity)
    :Tavara(tLevel, rarity)
{
    this->aDefense = rand() % (tLevel * (rarity+1));
    this->aDefense += (rarity+1) * 6;
    this->tyyppi = rand() % 4;

    switch(this->tyyppi)
    {
        case armoriTyyppi::HEAD:
            this->tyyppiStr = "P\x84\x84hine";
            break;
        case armoriTyyppi::CHEST:
            this->tyyppiStr = "Rintasuojus";
            break;
        case armoriTyyppi::ARMS:
            this->tyyppiStr = "K\x84sisuojat:";
            break;
        case armoriTyyppi::LEGS:
            this->tyyppiStr = "Jalkasuojukset";
            break;
        default:
            this->tyyppiStr = "Error!";
            break;
    }

    this->setName(Armori::names[rand() % Armori::names.size()]);

    if (rarity == 4)
        this->aDefense += tLevel * 5;
    else if (rarity == 5)
        this->aDefense += tLevel * 10;

}

Armori::Armori(int tyyppi, int aDefense, string name, int tLevel, int bValue, int sValue, int rarity)
    : Tavara(name, tLevel, bValue, sValue, rarity)
{
    this->tyyppi = tyyppi;
    this->aDefense = aDefense;
}

Armori::~Armori()
{

}

Armori* Armori::clone() const
{
    return new Armori(*this);
}

string Armori::toString()const
{
    string str =
            this->getName()
            + " | Tyyppi: "
            + this->tyyppiStr
            + " | Lvl: "
            + std::to_string(this->getLevel())
            + " | Rarity: "
            + std::to_string(this->getRarity())
            + " | Def: "
            + std::to_string(this->aDefense);
            //+ " "
            //+ std::to_string(this->getsValue());

    return str;
}

