#pragma once

#include "STLINCLUDE.h"
#include "tavaraluettelo.h"
#include "vihollinen.h"

using namespace std;

class Hahmo
{
public:
    Hahmo();
    Hahmo(string m_name, int m_seikkailut, int m_raha, int m_level,
                  int m_exp, int m_strength, int m_vitality, int m_dexterity,
                  int m_intelligence, int m_hp, int m_stamina, int m_statPoints, int m_skillPoints);
    virtual ~Hahmo();

    //funktiot
    void initialize(const std::string m_name);
    void printStats() const; //tulostaa hahmoikkunan
    string getAsString()const;
    string getLuetteloAsString();
    void levelUp();
    void upStats();
    void addStat(int stat, int value);
    void kaytaTavaraa(unsigned index);
    inline void resetHp() {this->m_hp = this->m_hpMax; }
    void lisaaTavara(const Tavara &tavara) { this->tavaraluettelo.lisaaTavara(tavara); }



    //---
    inline const int& getSeikkailut() const { return this->m_seikkailut; }
    inline const std::string& getName() const { return this->m_name; }
    inline const int& getLevel() const { return this->m_level; }
    inline const int& getRaha() const { return this->m_raha; }
    inline const int& getExp() const { return this->m_exp; }
    inline const int& getExpNext() const { return this->m_expNext; }
    inline const int& getStatPoints() const { return this->m_statPoints; }
    inline const int& getHp() const { return this->m_hp; }
    inline const int& getHpMax() const { return this->m_hpMax; }
    bool isAlive() { return this->m_hp > 0; }
    inline const int& getStamina() const { return this->m_stamina; }
    inline const int& getDmgMin() const { return this->m_dmgMin; }
    inline const int& getDmgMax() const { return this->m_dmgMax; }
    inline const int getDmg() const { return rand() % this->m_dmgMax + this->m_dmgMin; }
    inline const int& getDefense() const { return this->m_defense; }
    inline const int& getTarkkuus() const { return this->m_tarkkuus; }

    //----
    inline void matkaaKuljettu(const int& matka) { this->m_seikkailut = matka; }
    inline void seikkaile() { this->m_seikkailut++; }
    inline void gainExp(const int m_exp) { this->m_exp += m_exp; }
    inline void gainRaha(const int m_raha) { this->m_raha += m_raha; }
    inline void maksaRaha(const int m_raha) { this->m_raha -= m_raha; }
    void takeDmg(int dmg);

private:

    int m_seikkailut; //Matka kuljettu

    Tavaraluettelo tavaraluettelo;
    Ase ase;

    //suojustyypit
    Armori armori;
    Armori armori_head;
    Armori armori_chest;
    Armori armori_arms;
    Armori armori_legs;
    int m_raha;

    //hahmomuuttujat
    std::string m_name;
    int m_level;
    int m_exp;
    int m_expNext;

    int m_strength;
    int m_vitality;
    int m_dexterity;
    int m_intelligence;

    int m_hp;
    int m_hpMax;
    int m_stamina;
    int m_staminaMax;
    int m_dmgMin;
    int m_dmgMax;
    int m_defense;
    int m_tarkkuus;
    int m_luck;

    int m_statPoints;
    int m_skillPoints;
};


