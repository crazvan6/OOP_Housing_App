
#include "Locuinta.h"
#include <iostream>
#include <string>

Locuinta::Locuinta() : nume_client(""), discount(0), pret_metru(0){}

Locuinta::Locuinta(string nume_client, int discount, int pret_metru) : nume_client(nume_client), discount(discount), pret_metru(pret_metru){}

Locuinta::~Locuinta(){}

Locuinta::Locuinta(const Locuinta& locuinta){
    this -> nume_client = locuinta.nume_client;
    this-> discount = locuinta.discount;
    this -> pret_metru = locuinta.pret_metru;
}
Locuinta& Locuinta::operator=(const Locuinta& locuinta){
    if(this == &locuinta)
        return *this;
    this -> nume_client = locuinta.nume_client;
    this -> discount = locuinta.discount;
    this -> pret_metru = locuinta.pret_metru;
    return *this;
}
string Locuinta::getNume(){
    return this -> nume_client;
}

int Locuinta::getDiscount(){
    return this -> discount;
}
int Locuinta::getPret(){
    return this -> pret_metru;
}
void Locuinta::setNume(string nume_client){
    this -> nume_client = nume_client;
}
void Locuinta::setDiscount(int discount){
    this -> discount = discount;
}
void Locuinta::setPret(int pret_metru){
    this -> pret_metru = pret_metru;
}
istream& operator>>(istream& in, Locuinta& locuinta){
    cout << "Introduceti numele clientului: ";
    in >> locuinta.nume_client;
    cout << "Introduceti discount-ul: ";
    in >> locuinta.discount;
    cout << "Introduceti pretul pe m^2: ";
    in >> locuinta.pret_metru;
    return in;
}

ostream& operator<<(ostream& out, Locuinta& locuinta){
    out << "Nume client: " << locuinta.nume_client << '\n';
    out << "Discount: " << locuinta.discount << " %\n";
    out << "Pret pe m^2: " << locuinta.pret_metru << " $\n";
    return out;
}
void Locuinta:: read(){
    cin >> *this;
}

void Locuinta:: screen(){
    cout << *this;
}