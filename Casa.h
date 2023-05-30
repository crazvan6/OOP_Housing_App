
#include <string>
#include "Locuinta.h"
using namespace std;
#ifndef POO_3_CASA_H
#define POO_3_CASA_H

class Casa : public Locuinta{
    int etaje;
    int* suprafete;
public:
    // Constructori

    Casa();
    Casa(string nume_client, int discount, int pret_metru, int etaje, int* suprafete);
    ~Casa();
    Casa(const Casa& casa);

    // Supraincarcari

    Casa& operator=(const Casa &casa);
    friend istream& operator>>(istream& in, Casa& casa);
    friend ostream& operator<<(ostream& out, Casa& casa);

    // Getter

    int getEtaje();
    int* getSuprafete();
    float getSuprafata();

    // Metode

    int pretChirie();
    void read();
    void screen();
};
#endif //POO_3_CASA_H
