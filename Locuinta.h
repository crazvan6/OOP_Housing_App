
#include <string>
using namespace std;
#ifndef POO_3_LOCUINTA_H
#define POO_3_LOCUINTA_H

class Locuinta {
    string nume_client;
    int discount;
    int pret_metru;
public:
    // Constructori

    Locuinta();
    Locuinta(string nume_client, int discount, int pret_metru);
    virtual ~Locuinta();
    Locuinta(const Locuinta& locuinta);

    // Supraincarcari

    friend istream& operator>>(istream& in, Locuinta& locuinta);
    friend ostream&operator<<(ostream& out, Locuinta& locuinta);
    Locuinta& operator=(const Locuinta& locuinta);

    // Getteri

    string getNume();
    //virtual float getSuprafata();
    int getDiscount();
    int getPret();

    // Setteri

    void setNume(string nume_client);
    //void setSuprafata(float suprafata_utila);
    void setDiscount(int discount);
    void setPret(int pret_metru);

    // Metode

    virtual void read();
    virtual void screen();
};
#endif //POO_3_LOCUINTA_H
