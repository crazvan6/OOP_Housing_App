
#include "Gestiune.h"
#include <iostream>
#ifndef POO_3_MENIU_H
#define POO_3_MENIU_H


class Meniu {

    const string afiseaza_specializare_casa = "Informatii-specializare-casa";
    const string adauga_gestiune_casa = "Adauga-tip-casa";
    const string adauga_gestiune_apartament = "Adauga-tip-apartament";
    const string numar_gestiuni_casa = "Afiseaza-gestiuni-casa";
    const string final = "Stop";

    Gestiune<Casa*> g_casa;
    Gestiune<Apartament*> g_apart;

    void Instructiuni(){
        cout << "Instructiuni de utilizare\n\n";
        cout << afiseaza_specializare_casa << " -> Afiseaza informatii pentru gestiune tip 'Casa'\n";
        cout << adauga_gestiune_casa << " -> Adauga casa in gestiune\n";
        cout <<  adauga_gestiune_apartament << " -> Adauga apartament in gestiune\n";
        cout << numar_gestiuni_casa << " -> Afiseaza numarul de case\n";
        cout << final << " -> Opreste executia\n\n";
    }
public:
    void Run(){
        Instructiuni();
        string comanda;
        //cout << "Introduceti comanda: ";
        cin >> comanda;
        while(comanda != final){
            try {
                if (comanda == adauga_gestiune_casa) {
                    Casa *c = new Casa;
                    cin >> *c;
                    g_casa += c;
                    //delete c;
                }
            }
            catch(string error){
                cout << error;
            }
            if(comanda == adauga_gestiune_apartament){
                    Apartament* ap = new Apartament;
                    cin >> *ap;
                    g_apart += ap;
                    //delete ap;
                }

            else if(comanda == afiseaza_specializare_casa){
                g_casa.afiseazaInfo();
            }
            else if(comanda == numar_gestiuni_casa){
                g_casa.totalCase();
            }
            else{
                //cout << "Comanda invalida, introduceti comanda noua: ";
            }
            cout << "Introduceti comanda noua: ";
            cin >> comanda;
        }
    }
};


#endif //POO_3_MENIU_H
