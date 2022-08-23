#include "vihollinen.h"

Vihollinen::Vihollinen(int vLevel)
{
    this->vLevel = vLevel;
    this->vHpMax = vLevel * 5;
    this->vHp = this->vHpMax;
    this->dmgMin = this->vLevel * 1;
    this->dmgMax = this->vLevel * 2;
    this->dropChance = rand() % 100 + 1;
    this->vDefense = rand() % vLevel * 3 + 1;
    this->vTarkkuus = rand() % vLevel * 3 + 1;

}

Vihollinen::~Vihollinen()
{

}

std::string Vihollinen::getAsString() const
{
    return "Leveli: " + std::to_string(this->vLevel) + "\n" +
            "Hp: " + std::to_string(this->vHp) + " / " + std::to_string(this->vHpMax) + "\n" +
            "Damage: " + std::to_string(this->dmgMin) + " - " + std::to_string(this->dmgMax) + "\n" +
            "Defense: " + std::to_string(this->vDefense) + "\n" +
            "Tarkkuus: " + std::to_string(this->vTarkkuus) + "\n" +
            "Drop Chance: " + std::to_string(this->dropChance) + "\n";
}

void Vihollinen::takeDmg(int dmg)
{
    this->vHp -= dmg;

    if (this->vHp <= 0)
    {
        this->vHp = 0;
    }
}
