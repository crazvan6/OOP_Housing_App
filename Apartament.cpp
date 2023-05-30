
#include "Apartament.h"
#include <iostream>

Apartament::Apartament() {}

Apartament::Apartament(string nume_client, int discount, int pret_metru, int etaj, float suprafata_utila): Locuinta(nume_client, discount, pret_metru), etaj(etaj), suprafata_utila(suprafata_utila) {}

Apartament::~Apartament() {}

Apartament::Apartament(const Apartament& apartament) : Locuinta(apartament){
    this -> etaj = apartament.etaj;
}

istream& operator>>(istream& in, Apartament& apartament){
    in >> static_cast<Locuinta&>(apartament);
    cout << "Introduceti etajul apartamentului: ";
    in >> apartament.etaj;
    cout << "Introduceti suprafata utila a apartamentului: ";
    in >> apartament.suprafata_utila;
    cout << '\n';
    return in;
}
ostream& operator<<(ostream& out, Apartament& apartament){
    out << "Nume client: " << apartament.getNume() << '\n';
    out << "Suprafata utila: " << apartament.getSuprafata() << " m^2\n";
    out << "Discount: " << apartament.getDiscount() << " %\n";
    out << "Pret pe m^2: " << apartament.getPret() << " $\n";
    out << "Etajul apartamentului: " << apartament.getEtaj() << '\n';
   return out;
}
Apartament& Apartament::operator=(const Apartament& apartament){
    if(this == &apartament)
        return *this;
    this -> etaj = apartament.etaj;
    return *this;
}

int Apartament::getEtaj(){
    return this -> etaj;
}
const float Apartament::getSuprafata(){
    return this -> suprafata_utila;
}
int Apartament::pretChirie(){
    int sum = this -> getSuprafata() * this -> getPret();
    return (sum - (this-> getDiscount() / 100.0) * sum);
}
void Apartament:: read(){
    cin >> *this;
}

void Apartament:: screen(){
    cout << *this;
}