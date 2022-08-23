#include "peli.h"

Peli::Peli()
{
    valinta = 0;
    playing = true;
    aktiivinenHahmo = 0;
    fileName = "hahmot.txt";


}

Peli::~Peli()
{

}


//funktiot
void Peli::initGame()
{
    ifstream in;
    in.open("hahmot.txt");

    Ase::initNames();
    Armori::initNames();

    if(in.is_open())
        this->lataaHahmo();
    else
    {
        this->teeUusiHahmo();
    }

    /*Ase w1(1, rand() % 5);
    Ase w2(1, rand() % 5);
    Ase w3(1, rand() % 5);

    cout << w1.getName() << w1.getDmgMax() << "\n\n";
    cout << w2.getName() << w2.getDmgMax() << "\n\n";
    cout << w3.getName() << w3.getDmgMax() << "\n\n";*/

    in.close();
}

void Peli::mainMenu()
{
    cout << "Paina ENTER jatkaaksesi..." << endl;
    cin.get();
    system("CLS");

    if(this->hahmot[aktiivinenHahmo].isAlive())
    {

    if(this->hahmot[aktiivinenHahmo].getExp() >=
            this->hahmot[aktiivinenHahmo].getExpNext())
    {
        cout << "LEVEL UP Saatavilla!" << endl << endl;
    }

    cout << "==== MAIN MENU ====" << endl << endl;
    cout << "= Aktiivinen hahmo: " << this->hahmot[aktiivinenHahmo].getName()
         << " | hahmoID:  " << this->aktiivinenHahmo + 1 << " / " << this->hahmot.size()
         << " =" << endl << endl;
    cout << "0: Lopetus" << endl;
    cout << "1: Seikkaile" << endl;
    cout << "2: Kauppa" << endl;
    cout << "3: Level up" << endl;
    cout << "4: Lepo" << endl;
    cout << "5: Hahmon tiedot" << endl;
    cout << "6: Tavaraluettelo" << endl;
    cout << "7: Tee uusi hahmo" << endl;
    cout << "8: Valitse hahmo" << endl;
    cout << "9: Tallenna hahmot" << endl;
    cout << "10: Lataa hahmot" << endl;
    cout << endl;

    cout << endl << "Valinta: ";
    cin >> this->valinta;

    while(cin.fail())
    {
        cout << "Virheellinen valinta" << endl;
        cin.clear();
        cin.ignore(100, '\n');

        cout << endl << "Valinta: ";
        cin >> this->valinta;
    }

    cin.ignore(100, '\n');
    cout << endl;

    switch (this->valinta)
    {
    case 0: //LOPETA PELI
        playing = false;
        this->tallennaHahmo();
        break;
    case 1: //Seikkaileminen
        Seikkaile();
        break;
    case 3: //Level up
        this->levelUpHahmo();
        break;
    case 4: //Lepo
        Lepo();
        break;
    case 5: //hahmon tietojen tulostaminen
        hahmot[aktiivinenHahmo].printStats();
        break;
    case 6: //Tavaraluettelo
        cout << this->hahmot[aktiivinenHahmo].getLuetteloAsString();
        break;
    case 7: //uuden hahmon tekeminen ja pelin talennus
        teeUusiHahmo();
        tallennaHahmo();
        break;
    case 8: //hahmojen tallentaminen
        valitseHahmo();
        break;
    case 9: //hahmojen lataaminen
        tallennaHahmo();
        break;
    case 10: //hahmojen valinta
        lataaHahmo();
        break;
    default:
        break;
    }
    }
    else
    {
        cout << "==*** OLET KUOLLUT, LATAA PELI? ***==" << endl << endl;
        cout << "(0) Kyll\x84, (1) Ei" << endl;
        cin >> this->valinta;

        while(cin.fail() || this->valinta < 0 || this->valinta > 1) //valinnan tarkistaja
        {
            cout << "Virheellinen valinta" << endl;
            cin.clear();
            cin.ignore(100, '\n');

            cout << endl <<  "(0) Kyll\x84, (1) Ei";
            cin >> this->valinta;
        }

        cin.ignore(100, '\n');
        cout << endl;

        if (this->valinta == 0)
            this->lataaHahmo();
        else
            playing = false;
    }
}

void Peli::teeUusiHahmo()
{
    string m_name = "";
    cout << "Hahmon nimi: ";
    getline(cin, m_name);

    for (size_t i = 0; i < this->hahmot.size(); i++)
    {
        while (m_name == this->hahmot[i].getName())
        {
            cout << "Error! Hahmo on jo olemassa!" << endl;
            cout << "Hahmon nimi: ";
            getline(cin, m_name);
        }
    }


    hahmot.push_back(Hahmo());
    aktiivinenHahmo = hahmot.size() - 1;
    hahmot[aktiivinenHahmo].initialize(m_name);
}

void Peli::levelUpHahmo()
{
    this->hahmot[aktiivinenHahmo].levelUp();

    if (this->hahmot[aktiivinenHahmo].getStatPoints() > 0)
    {
        cout << "Sinulla on lis\x84tt\x84vi\x84 statpointseja!\n\n";
        cout << "Lis\x84tt\x84v\x84 statti: " << "\n";
        cout << "0: Strength" << endl;
        cout << "1: Vitality" << endl;
        cout << "2: Dexterity" << endl;
        cout << "3: Intelligence" << endl;
        cin >> this->valinta;

        while(cin.fail() || this->valinta > 3)
        {
            cout << "Virheellinen valinta" << endl;
            cin.clear();
            cin.ignore(100, '\n');

            cout << endl << "Valitse +1: "; //valitse mitä stattia haluat nostaa yhdellä
            cin >> this->valinta;
        }

        cin.ignore(100, '\n');
        cout << endl;

        switch (this->valinta)
        {
            case 0: //strength
               this->hahmot[aktiivinenHahmo].addStat(0,1);
                break;
            case 1: //vitality
                this->hahmot[aktiivinenHahmo].addStat(1,1);
                break;
            case 2: //dexterity
                this->hahmot[aktiivinenHahmo].addStat(2,1);
                break;
            case 3: //intelligence
                this->hahmot[aktiivinenHahmo].addStat(3,1);
                break;
            default:
                break;
        }



    }
}

void Peli::tallennaHahmo()
{
    ofstream outFile(fileName);

    if (outFile.is_open())
    {
        for (size_t i = 0; i < hahmot.size(); i++)
        {
            outFile << hahmot[i].getAsString() << "\n";
        }
    }
    outFile.close();
}

void Peli::lataaHahmo()
{
    ifstream inFile(fileName);

    this->hahmot.clear();

    string m_name = "";
    int m_seikkailut = 0;
    int m_raha = 0;
    int m_level = 0;
    int m_exp = 0;
    int m_strength = 0;
    int m_vitality = 0;
    int m_dexterity = 0;
    int m_intelligence = 0;
    int m_hp = 0;
    int m_stamina = 0;
    int m_statPoints = 0;
    int m_skillPoints = 0;

    string line = "";
    stringstream str;

    if (inFile.is_open())
    {
        while (getline(inFile, line))
        {
            str.str(line);
            str >> m_name;
            str >> m_seikkailut;
            str >> m_raha;
            str >> m_level;
            str >> m_exp;
            str >> m_strength;
            str >> m_vitality;
            str >> m_dexterity;
            str >> m_intelligence;
            str >> m_hp;
            str >> m_stamina;
            str >> m_statPoints;
            str >> m_skillPoints;

            Hahmo temp(m_name, m_seikkailut, m_raha, m_level, m_exp, m_strength,
                  m_vitality, m_dexterity, m_intelligence, m_hp, m_stamina,
                  m_statPoints, m_skillPoints);

            this->hahmot.push_back(Hahmo(temp));

            //cout << this->hahmot[0].getAsString() << endl;
            cout << "Hahmo: " << m_name << " ladattu.\n" ;;
            str.clear();
        }
    }
    inFile.close();

    if(this->hahmot.size() <= 0)
    {
        throw "VIRHE! EI HAHMOJA!";
    }
}

void Peli::valitseHahmo()
{
    cout << "Valitse hahmo: " << endl << endl;

    for (size_t i = 0; i < this->hahmot.size(); i++)
    {
        cout << "Index: " << i << " = " << this->hahmot[i].getName() << " Level: " << this->hahmot[i].getLevel() << endl;
    }

    cout << "\nValinta: ";

    cin >> this->valinta;

    while(cin.fail() || this->valinta >= this->hahmot.size() || this->valinta < 0) //väärä valinta
    {
        cout << "Virheellinen valinta" << endl;
        cin.clear();
        cin.ignore(100, '\n');

        cout << endl << "Valitse hahmo: "; //valitse mitä stattia haluat nostaa yhdellä
        cin >> this->valinta;
    }

    cin.ignore(100, '\n');
    cout << endl << endl;

    this->aktiivinenHahmo = this->valinta;

    cout << this->hahmot[this->aktiivinenHahmo].getName() << " valittu pelattavaksi hahmoksi!" << endl;
}

void Peli::Seikkaile()
{
    this->hahmot[aktiivinenHahmo].seikkaile();

    Tapahtuma th;

    th.luoTapahtuma(this->hahmot[aktiivinenHahmo], this->viholliset);
}

void Peli::Lepo()
{
    int lepoHinta = this->hahmot[this->aktiivinenHahmo].getHpMax() - this->hahmot[this->aktiivinenHahmo].getHp();

    cout << "= LEPOPAIKKA =" << "\n\n";
    cout << "Lep\x84\x84minen maksaa sinulle: ";
    cout << lepoHinta << "\n";
    cout << "Rahasi: ";
    cout << this->hahmot[this->aktiivinenHahmo].getRaha() << "\n";
    cout << "HP: " << this->hahmot[this->aktiivinenHahmo].getHp() << " / "
         << this->hahmot[this->aktiivinenHahmo].getHpMax() << "\n\n";

    if (this->hahmot[this->aktiivinenHahmo].getRaha() < lepoHinta)
        cout << "Ei varaa lep\x84\x84miseen." << "\n\n";
    else if (this->hahmot[this->aktiivinenHahmo].getHp() >= this->hahmot[this->aktiivinenHahmo].getHpMax())
    {
        cout << "Ei tarvetta lev\x84t\x84" << "\n\n";
    }
    else
    {

    cout << "\n\nLep\x84\x84? (0) Kyll\x84, (1) Ei" << "\n";

    cin >> this->valinta;

    while(cin.fail() || this->valinta < 0 || this->valinta > 1) //valinnan tarkistaja
    {
        cout << "Virheellinen valinta" << endl;
        cin.clear();
        cin.ignore(100, '\n');

        cout << endl <<  "\n\nLep\x84\x84? (0) Kyll\x84, (1) Ei" << "\n";
        cin >> this->valinta;
    }

    cin.ignore(100, '\n');
    cout << endl;

    if (this->valinta == 0)
    {
        this->hahmot[this->aktiivinenHahmo].resetHp();
        this->hahmot[this->aktiivinenHahmo].maksaRaha(lepoHinta);
        cout << "Lep\x84sit hyvin.\n\n";
    }
    else
    {
        cout << "Ehk\x84 ensikerralla sitten.\n\n";
    }

    }
}
