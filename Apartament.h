
#include "Locuinta.h"
#ifndef POO_3_APARTAMENT_H
#define POO_3_APARTAMENT_H

class Apartament : public Locuinta {
    int etaj;
    float suprafata_utila;
public:
    // Constructori

    Apartament();
    Apartament(string nume_client, int discount, int pret_metru, int etaj, float suprafata_utila);
    ~Apartament();
    Apartament(const Apartament& apartament);

    //Supraincarcari
    friend istream& operator>>(istream& in, Apartament& apartament);
    friend ostream& operator<<(ostream& out, Apartament& apartament);
    Apartament& operator=(const Apartament& apartament);

    // Getter
    int getEtaj();
    const float getSuprafata();

    // Metode

    virtual int pretChirie();
    void read();
    void screen();

};
#endif //POO_3_APARTAMENT_H
