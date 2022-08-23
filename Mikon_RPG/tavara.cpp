#include "tavara.h"

Tavara::Tavara()
{
    this->name = "EMPTY";
    this->tLevel = 0;
    this->bValue = 0;
    this->sValue = 0;
    this->rarity = 0;
}

Tavara::Tavara(int tLevel, int rarity)
{
    this->name = "NONE";
    this->tLevel = rand() % (tLevel+2) + 1;
    this->bValue = tLevel * this->rarity * 10;
    this->sValue = this->bValue / 2;
    this->rarity = rarity;
}

Tavara::Tavara(std::string name, int tLevel, int bValue, int sValue, int rarity)
{
    this->name = name;
    this->tLevel = tLevel;
    this->bValue = bValue;
    this->sValue = sValue;
    this->rarity = rarity;
}

Tavara::~Tavara()
{

}
