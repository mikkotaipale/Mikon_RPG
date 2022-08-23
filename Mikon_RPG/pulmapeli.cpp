#include "pulmapeli.h"

Pulmapeli::Pulmapeli(std::string fileName)
{
    this->oikeaVastaus = 0;


    std::ifstream inFile(fileName);

    int vMaara = 0; //vastausten määrä
    std::string vastaus = ""; //vastaus
    int oikeaV = 0; //oikea vastaus

    if (inFile.is_open())
    {
        std::getline(inFile, this->kysymys);
        inFile >> vMaara;
        inFile.ignore();

        for (size_t i = 0; i < vMaara; i++)
        {
            std::getline(inFile, vastaus);
            this->vastaukset.push_back(vastaus);
        }

        inFile >> oikeaV;
        this->oikeaVastaus = oikeaV;
        inFile.ignore();
    }
    else
        throw("Pulmapelin avaaminen ei onnistunut.");

    inFile.close();
}

Pulmapeli::~Pulmapeli()
{

}

std::string Pulmapeli::getAsString()
{
    std::string vastaukset = "";

    for (size_t i = 0; i < this->vastaukset.size(); i++)
    {
        vastaukset += std::to_string(i) + ": " + this->vastaukset[i] + "\n";
    }
    /*return this->kysymys + "\n"
            + vastaukset + "\n"
            + std::to_string(this->oikeaVastaus) + "\n";*/
    return this->kysymys + "\n"
            + vastaukset + "\n";

}
