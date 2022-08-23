#pragma once

#include "STLINCLUDE.h"
#include "ase.h"
#include "armori.h"


class Tavaraluettelo
{
public:
    Tavaraluettelo();
    ~Tavaraluettelo();
    Tavaraluettelo(const Tavaraluettelo &obj);
    inline int size(){ return this->tMaara; };
    Tavara& operator[](const int index);
    void lisaaTavara(const Tavara &tavara);
    void poistaTavara(int index);
    inline void debugPrint() const
    {
        for (size_t i = 0; i < this->tMaara; i++)
        {
            std::cout << this->tavaraTaulukko[i]->debugPrint() << std::endl;
        }
    }
private:
    int tRaja; //Tavaroiden maksimi määrä
    int tMaara; //Tavaroiden määrä
    Tavara **tavaraTaulukko;

    void laajennus();
    void initialize(const int from = 0);



};


