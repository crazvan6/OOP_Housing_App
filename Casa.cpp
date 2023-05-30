
#include "Casa.h"
#include <iostream>

Casa::Casa() {}

Casa::Casa(string nume_client, int discount, int pret_metru, int etaje, int* suprafete) : Locuinta(nume_client, discount, pret_metru), etaje(etaje), suprafete(suprafete) {}

Casa::~Casa() {}

Casa::Casa(const Casa& casa) : Locuinta(casa){
    this -> etaje = casa.etaje;
    this -> suprafete = casa.suprafete;
}

Casa& Casa::operator=(const Casa& casa){
    if(this == &casa)
        return *this;
    Casa::operator=(casa);
    this -> etaje = casa.etaje;
    this -> suprafete = casa.suprafete;
    return *this;
}

istream& operator>>(istream& in, Casa& casa){
    in >> static_cast<Locuinta&>(casa);
    cout << "Introduceti numarul de etaje ale casei: ";
    in >> casa.etaje;
    //delete[] casa.suprafete;
    casa.suprafete = new int[casa.etaje + 1];
    cout << "Introduceti suprafata utila a curtii: ";
    in >> casa.suprafete[0];
    for(int i = 1; i < casa.etaje + 1; ++i){
        cout << "Introduceti suprafata utila a etajului " << i <<": ";
        in >> casa.suprafete[i];
    }
    cout << '\n';
    return in;
}

ostream& operator<<(ostream& out, Casa& casa){
    out << "Nume client: " << casa.getNume() << '\n';
    out << "Suprafata utila totala: " << casa.getSuprafata() << " m^2\n";
    out << "Discount: " << casa.getDiscount() << " %\n";
    out << "Pret pe m^2: " << casa.getPret() << " $\n";
    out << "Numarul de etaje ale casei: " << casa.getEtaje() << '\n';
    return out;
}

int Casa::getEtaje(){
    return this -> etaje;
}

float Casa::getSuprafata(){
    float suprafata = 0;
    for(int i = 0; i < this -> etaje + 1; ++i){
        suprafata += this -> suprafete[i];
    }
    return suprafata;
}

int* Casa::getSuprafete(){
    return this -> suprafete;
}

int Casa::pretChirie(){
    int pret = 0;
    for(int i = 0; i < this -> etaje + 1; ++i){
        pret += this -> suprafete[i] * this -> getPret();
    }
    return (pret - (this-> getDiscount() / 100.0) * pret);
}

void Casa::read(){
    cin >> *this;
}

void Casa::screen(){
    cout << *this;
}