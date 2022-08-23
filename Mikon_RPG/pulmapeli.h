#pragma once

#include "STLINCLUDE.h"

class Pulmapeli
{
public:
    Pulmapeli(std::string fileName);
    virtual ~Pulmapeli();
    std::string getAsString();

    inline const int& getOikeaVastaus()const { return this->oikeaVastaus; }

private:
    std::string kysymys;
    std::vector<std::string> vastaukset;
    int oikeaVastaus;

};

