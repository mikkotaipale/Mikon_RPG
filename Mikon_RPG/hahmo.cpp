#include "hahmo.h"
#include <cmath>

Hahmo::Hahmo()
{
    this->m_seikkailut = 0;

    this->m_raha = 0;

    this->m_name = "";
    this->m_level = 0;
    this->m_exp = 0;
    this->m_expNext = 0;

    this->m_strength = 0;
    this->m_vitality = 0;
    this->m_dexterity = 0;
    this->m_intelligence = 0;

    this->m_hp = 0;
    this->m_hpMax = 0;
    this->m_stamina = 0;
    this->m_staminaMax = 0;
    this->m_dmgMin = 0;
    this->m_dmgMax = 0;
    this->m_defense = 0;
    this->m_tarkkuus = 0;
    this->m_luck = 0;

    this->m_statPoints = 0;
    this->m_skillPoints = 0; //ei käyttöä vielä
}

Hahmo::Hahmo(string m_name, int m_seikkailut, int m_raha, int m_level,
              int m_exp, int m_strength, int m_vitality, int m_dexterity,
              int m_intelligence, int m_hp, int m_stamina, int m_statPoints, int m_skillPoints)
{
    this->m_seikkailut = m_seikkailut;

    this->m_raha = m_raha;

    this->m_name = m_name;
    this->m_level = m_level;
    this->m_exp = m_exp;
    this->m_expNext = 0;

    this->m_strength = m_strength;
    this->m_vitality = m_vitality;
    this->m_dexterity = m_dexterity;
    this->m_intelligence = m_intelligence;

    this->m_hp = m_hp;
    this->m_hpMax = 0;
    this->m_stamina = m_stamina;
    this->m_staminaMax = 0;
    this->m_dmgMin = 0;
    this->m_dmgMax = 0;
    this->m_defense = 0;
    this->m_tarkkuus = 0;
    this->m_luck = 0;

    this->m_statPoints = m_statPoints;
    this->m_skillPoints = m_skillPoints;

    /*this->tavaraluettelo.lisaaTavara(Ase(1, rand() % 5));
    this->tavaraluettelo.lisaaTavara(Armori(1, rand() % 5));
    this->tavaraluettelo.lisaaTavara(Ase(1, rand() % 5));
    this->tavaraluettelo.lisaaTavara(Armori(1, rand() % 5));*/

    this->upStats();
}

Hahmo::~Hahmo()
{

}

//funktiot
void Hahmo::initialize(const string m_name)
{

    this->m_seikkailut = 0;

    this->m_raha = 100;

    this->m_name = m_name;
    this->m_level = 1;
    this->m_exp = 0;

    this->m_strength = 5;
    this->m_vitality = 5;
    this->m_dexterity = 5;
    this->m_intelligence = 5;

    this->m_statPoints = 0;
    this->m_skillPoints = 0;

    this->upStats();
}

void Hahmo::printStats() const
{
    cout << "===== Hahmon tiedot =====" << endl;
    cout << "= Nimi: " << this->m_name << endl;
    cout << "= Leveli: " << this->m_level << endl;
    cout << "= Exp: " << this->m_exp << endl;
    cout << "= Exp seuraavalle levelille: " << this->m_expNext << endl;
    cout << "= Stat pisteet: " << this->m_statPoints << endl;
    cout << endl;
    cout << "= Strength: " << this->m_strength << endl;
    cout << "= Vitality: " << this->m_vitality << endl;
    cout << "= Dexterity: " << this->m_dexterity << endl;
    cout << "= Intelligence: " << this->m_intelligence << endl;
    cout << endl;
    cout << "= HP: " << this->m_hp << " / " << this->m_hpMax << endl;
    cout << "= Stamina: " << this->m_stamina << " / " << this->m_staminaMax << endl;
    cout << "= Damage: " << this->m_dmgMin << " - " << this->m_dmgMax << endl;
    cout << "= Defense: " << this->m_defense << endl;
    cout << "= Tarkkuus: " << this->m_tarkkuus << endl;
    cout << "= Luck: " << this->m_luck << endl;
    cout << "= Raha: " << this->m_raha << endl;
    cout << "= Kuljettu matka (km): " << this->m_seikkailut << endl;
    cout << endl;
    cout << "= Ase:\t\t" << this->ase.getName()
         << " iLvl:\t" << this->ase.getLevel()
         << " Dmg:\t"  << this->ase.getDmgMin() << " - " << this->ase.getDmgMax() << endl;
    cout << "= P\x84\x84suojus:\t" << this->armori_head.getName()
         << " iLvl:\t" << this->armori_head.getLevel()
         << " Def:\t" << this->armori_head.getDefense() << endl;
    cout << "= Rintasuojus:\t" << this->armori_chest.getName()
         << " iLvl:\t" << this->armori_chest.getLevel()
         << " Def:\t" << this->armori_chest.getDefense() << endl;
    cout << "= K\x84sineet:\t" << this->armori_arms.getName()
         << " iLvl:\t" << this->armori_arms.getLevel()
         << " Def:\t" << this->armori_arms.getDefense() << endl;
    cout << "= Jalkasuojat:\t" << this->armori_legs.getName()
         << " iLvl:\t" << this->armori_legs.getLevel()
         << " Def:\t" << this->armori_legs.getDefense() << endl;

    cout << endl;

}

string Hahmo::getAsString() const
{
    return m_name + " "
        + to_string(m_seikkailut) + " " //kuljetun matkan pituus
        + to_string(m_raha) + " "
        + to_string(m_level) + " "
        + to_string(m_exp) + " "
        + to_string(m_strength) + " "
        + to_string(m_vitality) + " "
        + to_string(m_dexterity) + " "
        + to_string(m_intelligence) + " "
        + to_string(m_hp) + " "
        + to_string(m_stamina) + " "
        + to_string(m_statPoints) + " "
        + to_string(m_skillPoints);

}

string Hahmo::getLuetteloAsString()
{
    string tvl;

    for (size_t i = 0; i < this->tavaraluettelo.size(); i++)
    {
        tvl += to_string(i) + ":" + this->tavaraluettelo[i].toString() + "\n";
    }

    return tvl;
}

//Levelin saanti
void Hahmo::levelUp()
{
    if (m_exp >= m_expNext)
    {
        m_exp -= m_expNext;
        m_level++;

        this->m_expNext = static_cast<int>((50/3)*((pow(m_level,3)
                          - 6 * pow(m_level,2))
                          + 17*m_level - 12)) + 100;

        this->m_statPoints++;
        this->m_skillPoints++;

        this->upStats();


        cout << "Olet nyt levelill\x84 " <<this->m_level << " !!!" << endl;
    }
    else
    {
        cout << "Ei tarpeeksi expaa seuraavalle levelille" << endl;

    }
}

//statsien päivitys
void Hahmo::upStats()
{
    this->m_expNext = static_cast<int>(
                (50/3)*((pow(m_level, 3)
                - 6 * pow(m_level, 2))
                + 17 * m_level - 12)) + 100;

    this->m_hpMax = (this->m_vitality * 2) + (this->m_strength / 2) + this->m_level*5;
    this->m_hp = this->m_hpMax;
    this->m_staminaMax = this->m_vitality + (this->m_strength / 2) + (this->m_dexterity / 2);
    this->m_dmgMin = this->m_strength;
    this->m_dmgMax = this->m_strength + 2;
    this->m_defense = this->m_dexterity + (this->m_intelligence / 2);
    this->m_tarkkuus = (this->m_dexterity / 2)  + this->m_intelligence;
    this->m_luck = this->m_intelligence;
}
//stasien laitto
void Hahmo::addStat(int stat, int value)
{
    if(this->m_statPoints < value)
        cout << "Ei tarpeeksi stattipojoja. " << endl;
    else
    {
        switch (stat)
        {
        case 0:
            this->m_strength += value;
            cout << "Strength +1 !" << endl;
            break;
        case 1:
            this->m_vitality += value;
            cout << "Vitality +1 !" << endl;
            break;
        case 2:
            this->m_dexterity += value;
            cout << "Dexterity +1 !" << endl;
            break;
        case 3:
            this->m_intelligence += value;
            cout << "Intelligence +1 !" << endl;
            break;
        default:
            cout << "Virhe valinnassa." << endl;
            break;
        }

    this->m_statPoints -= value;

    this->upStats();
    }

}

void Hahmo::kaytaTavaraa(unsigned index)
{
    if (index < 0 || index >= this->tavaraluettelo.size())
    {
        cout << "Ei tavaraa valittu.\n\n";
    }
    else
    {
    Ase *w = nullptr;
    w = dynamic_cast<Ase*>(&this->tavaraluettelo[index]);

    Armori *a = nullptr;
    a = dynamic_cast<Armori*>(&this->tavaraluettelo[index]);
    //tavara on ase
    if(w != nullptr)
    {
        this->ase = *w;
    }
    else if (a != nullptr)
    {
        switch(a->getType())
        {
        case armoriTyyppi::HEAD:
            this->armori_head = *a;
                break;
        case armoriTyyppi::CHEST:
            this->armori_chest = *a;
                break;
        case armoriTyyppi::ARMS:
            this->armori_arms = *a;
                break;
        case armoriTyyppi::LEGS:
            this->armori_legs = *a;
                break;
        default:
            cout << "ERROR, ARMORITYYPPIA EI OLE" << endl;
            break;
        }
    }
    else
    {
        cout << "ERROR" << endl << endl;
    }
    }
}





void Hahmo::takeDmg(const int dmg)
{
    this->m_hp -= dmg;

    if (this->m_hp <= 0)
    {
        this->m_hp = 0;
    }


}
