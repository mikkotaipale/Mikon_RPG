#include "tavaraluettelo.h"

Tavaraluettelo::Tavaraluettelo()
{
    this->tRaja = 5; //tavaroiden maksimimäärä
    this->tMaara = 0; //tavaroiden määrä
    this->tavaraTaulukko = new Tavara*[tRaja];
    this->initialize();
}

Tavaraluettelo::~Tavaraluettelo()
{
    for (size_t i = 0; i < this->tMaara; i++)
    {
        delete this->tavaraTaulukko[i];
    }
    delete[] this->tavaraTaulukko;
}

Tavaraluettelo::Tavaraluettelo(const Tavaraluettelo &obj) //tavaran kopionti konstruktori
{
    this->tRaja = obj.tRaja;
    this->tMaara = obj.tMaara;
    this->tavaraTaulukko = new Tavara*[this->tRaja];

    for (size_t i = 0; i < this->tMaara; i++)
    {
       this->tavaraTaulukko[i] = obj.tavaraTaulukko[i]->clone();
    }

    initialize(this->tMaara);
}

Tavara& Tavaraluettelo::operator[](const int index)
{
    if (index < 0 || index >= this->tMaara)
        throw("huono, paha paha indeksi!");

    return *this->tavaraTaulukko[index];
}

void Tavaraluettelo::laajennus()
{
    this->tRaja *= 2;

    Tavara **tmpTaul = new Tavara*[this->tRaja];

    for (size_t i = 0; i < this->tMaara; i++)
    {
        tmpTaul[i] = this->tavaraTaulukko[i];
    }

    delete [] this->tavaraTaulukko;

    this->tavaraTaulukko = tmpTaul;

    this->initialize(this->tMaara);
}
void Tavaraluettelo::initialize(const int from)
{
    for (size_t i = from; i < tRaja; i++)
    {
        this->tavaraTaulukko[i] = nullptr;
    }
}

void Tavaraluettelo::lisaaTavara(const Tavara &tavara)
{
    if(this->tMaara >= this->tRaja)
    {
        laajennus();
    }

    this->tavaraTaulukko[this->tMaara++] = tavara.clone();
}
void Tavaraluettelo::poistaTavara(int index)
{

}
