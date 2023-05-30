//Nume: Cutuliga Razvan-Ion
//Compilator: CLang
//Tutore: Alexandra Murgoci


#include <iostream>
#include <vector>
using namespace std;
class Drum{
    const string denumire;
    int lungime;
    int tronsoane;
    const int lungime_tronson;
public:
    Drum();
    Drum(string denumire, int lungime, int tronsoane);

    virtual ~Drum();

    Drum(const Drum& drum) = default;


    int getTronsoane();
    int getLungimeTronson(){ return lungime_tronson;}
    friend istream& operator>>(istream& in, Drum& drum);
    friend ostream& operator<<(ostream& out, Drum& drum);

    virtual void screen();

};
Drum::Drum() : lungime_tronson(0){}
Drum::Drum(string denumire, int lungime, int tronsoane) : denumire(denumire), lungime(lungime), tronsoane(tronsoane), lungime_tronson(lungime / tronsoane){}
//Drum::Drum(string denumire) : denumire(denumire){}
Drum::~Drum(){}
int Drum::getTronsoane(){
    return this -> tronsoane;
}
istream& operator>>(istream& in, Drum& drum){
    cout << "lungime: ";
    in >> drum.lungime;
    cout << "tronsoane: ";
    in >> drum.tronsoane;
    return in;
}
ostream& operator<<(ostream& out, Drum& drum){
    out << "denumire: " << drum.denumire << '\n';
    out << "lungime: " << drum.lungime << '\n';
    out << "tronsoane: " << drum.tronsoane << '\n';
    return out;
}
void Drum::screen(){
    cout << *this;
}




class DrumNational : public Drum{
    int judete;
public:
    DrumNational();
    DrumNational(string denumire, int lungime, int tronsoane, int judete) : Drum(denumire, lungime, tronsoane), judete(judete){}
    ~DrumNational(){}

    DrumNational(const DrumNational& drum) = default;

    friend istream& operator>>(istream& in, DrumNational& dnational);
    friend ostream& operator<<(ostream& out, DrumNational& dnational);

    void screen();
};

DrumNational::DrumNational(){}

istream& operator>>(istream& in, DrumNational& dnational){
    in >> dynamic_cast<Drum&> (dnational);
    cout << "judete: ";
    in >> dnational.judete;
    return in;
}
ostream& operator<<(ostream& out, DrumNational& dnational){
    out << dynamic_cast<Drum&>(dnational);
    out << "judete: "  << dnational.judete << '\n';
    return out;
}

void DrumNational::screen(){
    cout << *this;
}

class DrumEuro: public Drum{
    int tari;
public:
    DrumEuro();
    DrumEuro(string denumire, int lungime, int tronsoane, int tari) : Drum(denumire, lungime, tronsoane), tari(tari){}
    virtual ~DrumEuro(){}

    int getTari();
    DrumEuro(const DrumEuro& drum) = default;


    friend istream& operator>>(istream& in, DrumEuro& deuro);
    friend ostream& operator<<(ostream& out, DrumEuro& deuro);

    void screen();
};

DrumEuro::DrumEuro(){}
int DrumEuro::getTari(){
    return tari;
}
istream& operator>>(istream& in, DrumEuro& deuro){
    in >> dynamic_cast<Drum&> (deuro);
    cout << "tari: ";
    in >> deuro.tari;
    return in;
}
ostream& operator<<(ostream& out, DrumEuro& deuro){
    out << dynamic_cast<Drum&>(deuro);
    out << "tari: "  << deuro.tari << '\n';
    return out;
}

void DrumEuro::screen(){
    cout << *this;
}

class Autostrada : public DrumEuro{
    int benzi;
public:
    Autostrada(){};
    Autostrada(string denumire, int lungime, int tronsoane, int tari, int benzi) : DrumEuro(denumire, lungime, tronsoane, tari), benzi(benzi){}
    ~Autostrada() {}

    int getBenzi();

    Autostrada(const Autostrada& autostrada) = default;

    friend istream& operator>>(istream& in, Autostrada& autostrada);
    friend ostream& operator<<(ostream& out, Autostrada& autostrada);

    // void screen();
};

int Autostrada::getBenzi(){
    return benzi;
}
istream& operator>>(istream& in, Autostrada& autostrada){
    in >> dynamic_cast<DrumEuro&>(autostrada);
    cout << "benzi: ";
    in >> autostrada.benzi;
    return in;
}
ostream& operator<<(ostream& out, Autostrada& autostrada){
    out << dynamic_cast<DrumEuro&>(autostrada);
    out << "benzi: " << autostrada.benzi << '\n';
    return out;
}

class Contract : public Drum{
    const string nume;
    const int cif;
    static int idContract;
public:
    Contract(): nume(""), cif(0){}
    Contract(string nume, int cif, int tronson);
    ~Contract(){}


    Contract(const Contract& contract) = default;

    static float cost_non_autostrada(Contract& c, Drum& drum);
    static float cost_autostrada(Contract& c, Autostrada& autostrada);
    static float cost_european(Contract& c, DrumEuro& deuro);

    void screen();


};
int Contract::idContract = 0;
Contract::Contract(string nume, int cif, int tronson) : cif(cif) {
    idContract ++;
    if(tronson > this -> getTronsoane()){
        throw "Tronson inexistent";
    }
}
void Contract::screen(){
    cout << this -> cif;
    cout << this -> nume;
}
float Contract::cost_non_autostrada(Contract& c, Drum& d){
    float cost = 3000*d.getLungimeTronson();
    return cost;
}

float Contract:: cost_autostrada(Contract& c, Autostrada& autostrada){
    float cost = 3000*autostrada.getBenzi();
    return cost;
}
float Contract::cost_european(Contract& c, DrumEuro& deuro){
    float cost = 3000*deuro.getLungimeTronson();
    cost += 500*deuro.getTari();
    return cost;
}

int main(){
    vector<Drum*> list_drum;
    vector<Contract*> list_contract;
    int n;
    cin >> n;
    while(n--){
        cout << "Alege tip drum: simplu, european, national, autostrada : ";
        string tip;
        cin >> tip;
        if(tip == "simplu"){
            Drum* drum = new Drum();
            cin >> * drum;
            cout << "Cif contract: ";
            int cif;
            cin >> cif;
            cout << "Nume contract: ";
            string nume;
            cin >> nume;
            int tronson;
            cout << "tronson: ";
            cin >> tronson;
            try {
                Contract *contract = new Contract(nume, cif, tronson);
                list_contract.push_back(contract);
                list_drum.push_back(drum);
            }
            catch(string eroror){}
        }
        else if(tip == "european"){
            DrumEuro* deuro = new DrumEuro();
            cin >> *deuro;
            int cif;
            cin >> cif;
            cout << "Nume contract: ";
            string nume;
            cin >> nume;
            int tronson;
            cout << "tronson: ";
            cin >> tronson;
            try {
                Contract *contract = new Contract(nume, cif, tronson);
                list_contract.push_back(contract);
                list_drum.push_back(deuro);
            }
            catch(string eroror){}
        }
        else if(tip == "national"){
            DrumNational* dnational = new DrumNational();
            cin >> *dnational;
            int cif;
            cin >> cif;
            cout << "Nume contract: ";
            string nume;
            cin >> nume;
            int tronson;
            cout << "tronson: ";
            cin >> tronson;
            try {
                Contract *contract = new Contract(nume, cif, tronson);
                list_contract.push_back(contract);
                list_drum.push_back(dnational);
            }
            catch(string eroror){}
        }
        else if(tip == "autostrada"){
            Autostrada* autostrada = new Autostrada();
            cin >> *autostrada;
            int cif;
            cin >> cif;
            cout << "Nume contract: ";
            string nume;
            cin >> nume;
            int tronson;
            cout << "tronson: ";
            cin >> tronson;
            try {
                Contract *contract = new Contract(nume, cif, tronson);
                list_contract.push_back(contract);
                list_drum.push_back(autostrada);
            }
            catch(string eroror){}
        }
    }
    int ind = 0;
    for(auto& drum: list_drum){
        cout << drum;
        if(!dynamic_cast<Autostrada*>(drum)){
            Contract::cost_non_autostrada(*list_contract[ind++], *drum);
        }
        else if(dynamic_cast<Autostrada*>(drum)){
            Contract::cost_autostrada(*list_contract[ind++], static_cast<Autostrada &>(*drum));
        }
        else if(dynamic_cast<DrumEuro*>(drum)){
            Contract::cost_european(*list_contract[ind++], static_cast<DrumEuro &>(*drum));
        }
    }
    for(auto& contr: list_contract){
        contr -> screen();
    }
    return 0;
}