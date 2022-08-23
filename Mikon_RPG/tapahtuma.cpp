#include "tapahtuma.h"

Tapahtuma::Tapahtuma()
{
    this->tapMaara = 2;
}

Tapahtuma::~Tapahtuma()
{

}

void Tapahtuma::luoTapahtuma(Hahmo &hahmo, dArr<Vihollinen>& viholliset)
{
    int i = rand() % this->tapMaara;

    switch (i)
    {
    case 0:
        //Vihollisen kohtaaminen
        vKohtaaminen(hahmo, viholliset);
        break;
    case 1:
        //Pulmapeli
        pulmanRatkaisu(hahmo);
        break;
    case 2:
        break;
    default:
        break;
    }
}

//Eri tapahtumia
void Tapahtuma::vKohtaaminen(Hahmo &hahmo, dArr<Vihollinen>& viholliset)

{
    bool pelaajanVuoro = false;
    int valinta = 0;


    //kolikon heitto
    int arpa = rand() % 2 + 1;

    if (arpa == 1) // 50/50 kumman vuoro, arvotaan arpa, heitetään kolikkoa.
        pelaajanVuoro = true;
    else
        pelaajanVuoro = false;
    //lopputilanteet
    bool juokse = false; // karkuun lähteminen
    bool pelaajaTuhottu = false; //pelaaja häviää taistelun
    bool vihollinenTuhottu = false; //pelaaja voittaa taistelun

    //viholliset
    int nrOfEnemies = rand() % 4 + 1; // vihollisten määrä

    for (size_t i = 0; i < nrOfEnemies; i++)
    {
        viholliset.push(Vihollinen(hahmo.getLevel() + rand() % 3));
    }

    for (size_t i = 0; i < viholliset.size(); i++)
    {
        cout << i << ": "
             << "Level: " << viholliset[i].getLevel() << " | "
             << "HP: " << viholliset[i].getHp() << " / "
             << viholliset[i].getHpMax() << " | "
             << "Defense: " << viholliset[i].getDefense() << "\t| "
             << "Tarkkuus: " << viholliset[i].getTarkkuus() << "\t| "
             << "Damage: " << viholliset[i].getDmgMin() << " - "
             << viholliset[i].getDmgMax()
             << "\n";
    }

    //Taistelumuuttujat
    int dmg = 0;
    int gainExp = 0;
    int gainRaha = 0;
    int pTotal = 0;                 ;
    int vTotal = 0;
    int combatTotal = 0;
    int combatArpaP = 0;
    int combatArpaV = 0; //Taistelu laskurit arvat rollit pyöräytykset

    while(!juokse && !pelaajaTuhottu && !vihollinenTuhottu)
    {
        if(pelaajanVuoro && !pelaajaTuhottu)
            {
            //Taistelu-menu
            cout << "= PELAAJAN VUORO =" << "\n\n";
            cout << "Jatka..." << "\n\n";
            cin.get();
            system("CLS");



            cout << "======= TAISTELU MENU =======" << "\n\n";
            cout << "HP: " << hahmo.getHp() << " / " << hahmo.getHpMax() << endl << endl;

            cout << "0: Juokse\n"; //karkaa taistelusta
            cout << "1: Hakkaa vihua\n"; //hyökkää viholliseen
            cout << "2: Suojaus\n"; //suojaa seuraavan iskun
            cout << "3: K\x84yt\x84 tavaraa\n";

            cout << "\nValinta: ";

            cin >> valinta;

            while(cin.fail() || valinta >= 3 || valinta < 0) //väärä valinta
            {
                system("CLS");

                cout << "\n\nVirheellinen valinta" << endl;
                cin.clear();
                cin.ignore(100, '\n');

                cout << "======= TAISTELU MENU =======" << "\n\n";

                cout << "0: Juokse\n"; //karkaa taistelusta
                cout << "1: Hakkaa vihua\n"; //hyökkää viholliseen
                cout << "2: Suojaus\n"; //suojaa seuraavan iskun
                cout << "3: K\x84yt\x84 tavaraa\n";

                cout << "\nValinta: ";
                cin >> valinta;
            }


            cin.ignore(100, '\n');
            cout << endl << endl;

            //Valinnat
            switch (valinta)
            {
            case 0: //karkaa
                juokse = true;
                break;
            case 1: //hyökkää

                //valitse vihollinen
                cout << "Valitse kohde: " << "\n\n";

                for (size_t i = 0; i < viholliset.size(); i++)
                {
                    cout << i << ": "
                         << "Level: " << viholliset[i].getLevel() << " | "
                         << "HP: " << viholliset[i].getHp() << " / "
                         << viholliset[i].getHpMax() << " | "
                         << "Defense: " << viholliset[i].getDefense() << "\t| "
                         << "Tarkkuus: " << viholliset[i].getTarkkuus() << "\t| "
                         << "Damage: " << viholliset[i].getDmgMin() << " - "
                         << viholliset[i].getDmgMax()
                         << "\n";
                }

                cout << endl;

                cout << "\nValinta: ";

                cin >> valinta;

                while(cin.fail() || valinta >= viholliset.size() || valinta < 0) //väärä valinta
                {

                    cout << "\n\nVirheellinen valinta" << endl;
                    cin.clear();
                    cin.ignore(100, '\n');

                    cout << "Valitse kohde: " << "\n\n";

                    cout << "\nValinta: ";
                    cin >> valinta;
                }


                cin.ignore(100, '\n');
                cout << endl << endl;


                //Hyökkäyksen laskurit, arpominen
                combatTotal = viholliset[valinta].getDefense() + hahmo.getTarkkuus();
                vTotal = viholliset[valinta].getDefense() / (double)combatTotal * 100;
                pTotal = hahmo.getTarkkuus() / (double)combatTotal * 100;
                combatArpaP = rand() % (pTotal) + 1;
                combatArpaV = rand() % (vTotal) + 1;

                cout << "Pelaajan rolli: " << combatArpaP << "\n";
                cout << "Vihollisen rolli: " << combatArpaV << "\n\n";

                if (combatArpaP > combatArpaV) // osuma
                {
                    cout << "Osuma! " << "\n\n";

                    dmg = hahmo.getDmg();
                    viholliset[valinta].takeDmg(dmg);

                    cout << "Tehty damage: " << dmg << "!" << "\n\n";
                    cout << "_____________" << "\n";

                    if(!viholliset[valinta].isAlive())
                    {
                        cout << "Vihollinen tuhottu.\n\n";
                        gainExp = viholliset[valinta].getExp();
                        hahmo.gainExp(gainExp);
                        gainRaha = rand() % viholliset[valinta].getLevel() * 10 + 1;
                        hahmo.gainRaha(gainRaha);
                        cout << "Exp +" << gainExp << " !\n\n";
                        cout << "Raha +" << gainRaha << " !\n\n";



                        //Tavaran rollaus (droppi)
                        int roll = rand() % 100 + 1;
                        int rarity = -1;

                        if(roll > 20)
                        {
                            rarity = 0; //perus

                            int roll = rand() % 100 + 1;
                            if (roll > 30)
                            {
                                rarity = 1; //parempi

                                int roll = rand() % 100 + 1;
                                if (roll > 50)
                                {
                                    rarity = 2; //harvinainen

                                    int roll = rand() % 100 + 1;
                                    if (roll > 70)
                                    {
                                        rarity = 3; //eeppinen

                                        int roll = rand() % 100 + 1;
                                        if (roll > 80)
                                        {
                                            rarity = 4; //legendaarinen

                                            int roll = rand() % 100 + 1;
                                            if (roll > 80)
                                            {
                                                rarity = 5; //myyttinen
                                            }
                                        }
                                    }
                                }

                            }
                        }
                        if (roll >= 0)
                        {
                            roll = rand() % 100 * 1;

                            if (roll > 50)
                            {
                                Ase tempW(hahmo.getLevel(), rand() % 5);
                                hahmo.lisaaTavara(tempW);
                                cout << "Ase saatu droppina!" << endl;
                            }
                            else
                            {
                                Armori tempA(hahmo.getLevel(), rand() % 5);
                                hahmo.lisaaTavara(tempA);
                                cout << "Armori saatu droppina!" << endl;
                            }
                        }

                    viholliset.remove(valinta);
                    }



                }
                else //ei osumaa
                {
                    cout << "Ei osumaa\n\n";
                    cout << "\n_____________" << "\n\n";
                }
                break;
            case 2: //suojaa
                break;
            case 3: //käytä tavaraa
                break;
            default:
                break;
            }


            //Lopeta vuoro
            pelaajanVuoro = false;

           }

        else if (!pelaajanVuoro && !pelaajaTuhottu && !juokse && !vihollinenTuhottu)
        {

            cout << "\n* VIHOLLISEN VUORO *" << endl << endl;

            cout << "Jatka..." << endl << endl;
            cin.get();
            system("CLS");

            //vihollisen hyökkäys
            for (size_t i = 0; i < viholliset.size(); i++)
            {
                cout << "Jatka..." << endl << endl;
                cin.get();
                system("CLS");

                cout << "Vihollinen #" << i << "\n\n";

                //Hyökkäyksen laskurit, arpominen
                combatTotal = viholliset[i].getTarkkuus() + hahmo.getDefense();
                vTotal = viholliset[i].getTarkkuus() / (double)combatTotal * 100;
                pTotal = hahmo.getDefense() / (double)combatTotal * 100;
                combatArpaP = rand() % (pTotal) + 1;
                combatArpaV = rand() % (vTotal) + 1;

                cout << "Pelaajan rolli: " << combatArpaP << "\n";
                cout << "Vihollisen rolli: " << combatArpaV << "\n\n";

                if (combatArpaP < combatArpaV) // osuma
                {
                    cout << "Osuma! " << "\n\n";

                    dmg = viholliset[i].getDmg();
                    hahmo.takeDmg(dmg);

                    cout << "\n*****************" << "\n";
                    cout << "Vihollisen damage: " << dmg << "!" << "\n\n";
                    cout << "HP: " << hahmo.getHp() << " / " << hahmo.getHpMax() << endl << endl;

                    if(!hahmo.isAlive())
                    {
                        cout << "Sinut tuhottiin. Kuolit.\n\n";
                        pelaajaTuhottu = true;
                    }

                }
                else //ei osumaa
                {
                    cout << "Ei osumaa\n";
                    cout << "\n_____________" << "\n\n";
                }
            }

            //Lopeta vuoro
            pelaajanVuoro = true;
         }

        //tilanteet
        if (!hahmo.isAlive())
        {
            pelaajaTuhottu = true;
        }
        if (viholliset.size() <= 0)
        {
            vihollinenTuhottu = true;
        }

        //cout << pelaajanVuoro << juokse << pelaajaTuhottu << vihollinenTuhottu << "\n";
    }
}

void Tapahtuma::pulmanRatkaisu(Hahmo &hahmo)
{
    //std::cin.ignore();
    bool valmis = false;
    int kVastaus = 0; //pelaajan vastaus
    int yritykset = 3; //vastaus yritysten määrä
    int gainExp = (yritykset * hahmo.getLevel() * (rand()% 10 + 1));//expan saanti (kokemuspisteet)
    int gainRaha = (yritykset * hahmo.getLevel() * (rand()% 10 + 1));
    /*C:/Users/W7SUKS/Desktop/QT/C++/Lopputyö RPG/Mikon_RPG/build/*/

    Pulmapeli pulmapeli("pulmapelit/3.txt");



    while(!valmis && yritykset > 0)
    {

        yritykset --;
        std::cout << "Yritykset: " << yritykset << "\n\n";
        std::cout << pulmapeli.getAsString() << std::endl;

        std::cout << "\nVastauksesi: ";
        std::cin >> kVastaus;

        while(cin.fail())
        {
            cout << "Virheellinen vastaus" << endl;
            cin.clear();
            cin.ignore(100, '\n');

            cout << "Vastauksesi: ";
            cin >> kVastaus;
        }

        cin.ignore(100, '\n');
        cout << endl;

        std::cout << "\n";

        if(pulmapeli.getOikeaVastaus() == kVastaus)
        {
            valmis = true;

            hahmo.gainExp(gainExp);

            std::cout << "Sait " << gainExp << " exp!" << std::endl;
            std::cout << "Sait " << gainRaha << " rahaa!" << std::endl;//kokemuspisteiden määrän saamisen tulostus
            std::cout << "________________________________" << std::endl;
            //anna hahmolle expaa ja jatka
        }
    }
    if (valmis)
    {
        std::cout << "Vastaukseksi oli oikein \n\n";
    }
    else
    {
        std::cout << "Vastaukesi oli v\x84\x84rin \n\n";
    }
}
