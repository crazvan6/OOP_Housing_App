#include "Apartament.h"
#include "Casa.h"
#include "Locuinta.h"
#include <typeinfo>
#include <iostream>
#include <set>

#ifndef POO_3_GESTIUNE_H
#define POO_3_GESTIUNE_H

template<typename T>
class Gestiune {
    set<pair<Locuinta*, int>> locuinte;
    static int id;
    const int maxElemente;
public:
    Gestiune() ;
    ~Gestiune();
    void totalCase() const;
    static int getId();
    void afiseazaInfo() const;
    void operator+=(T ex);
};


template<class T>
int Gestiune<T>::id = 1;

template<class T>
Gestiune<T>::Gestiune() : maxElemente(2){
}

template<class T>
int Gestiune<T>::getId(){
    return id;
}
template<>
void Gestiune<Casa*>::totalCase() const {
    int count = 0;
    for (const auto& locuintaPair : locuinte) {
        Locuinta* locuinta = locuintaPair.first;
        if (typeid(*locuinta) == typeid(Casa)) {
            count++;
        }
    }
    cout << "Numarul de elemente de tip Casa: " << count << '\n';
}

template<>
void Gestiune<Casa*>::afiseazaInfo() const{
    float sumaIncasata = 0.0;
    for (const auto& locuintaPair : locuinte) {
        cout << "Indexul casei: " << locuintaPair.second << '\n';
        Locuinta* locuinta = locuintaPair.first;
        locuinta->screen();
        Casa* casaCpy = dynamic_cast<Casa*>(locuinta);
        if (casaCpy) {
            int etaje = casaCpy->getEtaje();
            int suprafataTotala = casaCpy->getSuprafata();
            int* suprafetecpy = casaCpy->getSuprafete();
            cout << "Numar etaje: " << etaje << '\n';
            cout << "Suprafata curte: " << suprafetecpy[0] << " m^2\n";
            cout << "Suprafata parter: " << suprafetecpy[1] << " m^2\n";
            for(int i = 2; i < etaje; ++i){
                cout << "Suprafata etajului " << i - 1 << ": " << suprafetecpy[i] << " m^2\n";
            }
            cout << "Suprafata totala proprietate: " << suprafataTotala << " m^2\n";
            int chirie = casaCpy->pretChirie();
            cout << "Cost chirie: " << chirie << " $\n\n";
            sumaIncasata += chirie;
            delete[] suprafetecpy;
        }
    }
    cout << "Suma totala incasata este " << sumaIncasata << " $\n\n\n";
}

template<typename T>
void Gestiune<T>::operator+=(T ex) {
    if(locuinte.size() >= maxElemente){
        throw "Numar maxim de elemente atins";
    }
    Locuinta* loc = dynamic_cast<Locuinta*>(ex);
    if (loc != nullptr) {
        locuinte.insert(make_pair(loc, id));
        id++;
    }
}
template<typename T>
Gestiune<T>::~Gestiune() {
    for (auto& pair : locuinte) {
        delete pair.first;
    }
    locuinte.clear();

}

#endif //POO_3_GESTIUNE_H
