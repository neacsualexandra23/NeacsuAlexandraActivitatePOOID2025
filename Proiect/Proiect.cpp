// Alexandra-Maria Neacsu  -  Articol A, Magazin M, Angajat N

#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class Angajat {
private:
    const int id;
    static int nrAngajati;
    string nume;
    string prenume;
    string cnp;
    char* functie;

public:
    ~Angajat() {
        delete[] functie;
    }

    Angajat() : id(++nrAngajati) {
        this->nume = "Necunoscut";
        this->prenume = "Necunoscut";
        this->cnp = "1234567890000";
        this->functie = new char[strlen("Necunoscut") + 1];
        strcpy_s(this->functie, strlen("Necunoscut") + 1, "Necunoscut");
    }

    Angajat(const string& nume, const string& prenume, const string& cnp) : id(++nrAngajati) {
        this->nume = nume;
        this->prenume = prenume;
        this->cnp = cnp;
        functie = nullptr;
    }

    Angajat(const string& nume, const string& prenume, const string& cnp, const char* functie) : id(++nrAngajati) {
        this->nume = nume;
        this->prenume = prenume;
        this->cnp = cnp;
        this->functie = new char[strlen(functie) + 1];
        strcpy_s(this->functie, strlen(functie) + 1, functie);
    }

    Angajat(const Angajat& other) : id(++nrAngajati) {
        this->nume = other.nume;
        this->prenume = other.prenume;
        this->cnp = other.cnp;
        this->functie = new char[strlen(other.functie) + 1];
        strcpy_s(this->functie, strlen(other.functie) + 1, other.functie);
    }

   int getId() const {
        return id;
    }
    string getNume() const {
        return nume; 
    }
 

    static int getNrAngajati() {
        return nrAngajati;
    }

  

    string getPrenume() const {
        return prenume;
    }

    string getCnp() const {
        return cnp;
    }

    const char* getFunctie() const {
       
        if (functie)
            return  functie;
        else return "Necunoscut";
    }

    void setNume(const string& nume) {
        this->nume = nume;
    }

    void setPrenume(const string& prenume) {
        this->prenume = prenume;
    }

    void setCnp(const string& cnp) {
        this->cnp = cnp;
    }

    void setFunctie(const char* functieNoua) {
        if (functieNoua == nullptr) return;

        // stergem ce era inainte
        delete[] functie;

        // alocam memorie noua
        functie = new char[strlen(functieNoua) + 1];
        strcpy_s(functie, strlen(functieNoua) + 1, functieNoua);
    }
    void AfisareAngajat() const {
        cout << "Angajatul: " << id << " " << nume << " " << prenume
            << " " << cnp << " - Functie: "
            << (functie ? functie : "Necunoscut") << endl;
    }

    //Angajat& operator=(const Angajat& other) = delete;

    friend ostream& operator<<(ostream& out, const Angajat& a) {
        out << "Angajat: ID=" << a.id
            << ", Nume=" << a.nume
            << ", Prenume=" << a.prenume
            << ", CNP=" << a.cnp
            << ", Functie=" << (a.functie ? a.functie : "Necunoscut");
        return out;
    }

};

int Angajat::nrAngajati = 0;

class Articol {
private:
    const int id;
    static int nrArticole;

    string nume;
    float pret;
    string* listaIngrediente;
    int nrIngrediente;
    int nrBucati;

public:
    ~Articol() {
        delete[] listaIngrediente;
    }

    Articol() : id(++nrArticole) {
        this->nume = "Necunoscut";
        this->pret = 0;
        this->listaIngrediente = nullptr;
        this->nrIngrediente = 0;
        this->nrBucati = 0;
    }

    Articol(const string& nume, float pret, int nrBucati, const string* ingrediente, int nrIngrediente) : id(++nrArticole) {
        this->nume = nume;
        this->pret = pret;
        this->nrBucati = nrBucati;
        this->nrIngrediente = nrIngrediente;

        if (nrIngrediente > 0 && ingrediente != nullptr) {
            this->listaIngrediente = new string[nrIngrediente];
            for (int i = 0; i < nrIngrediente; i++) {
                this->listaIngrediente[i] = ingrediente[i];
            }
        }
        else {
            listaIngrediente = nullptr;
            this->nrIngrediente = 0;
        }
    }

    Articol(const Articol& other) : id(++nrArticole) {
        this->nume = other.nume;
        this->pret = other.pret;
        this->nrBucati = other.nrBucati;
        this->nrIngrediente = other.nrIngrediente;

        if (other.listaIngrediente != nullptr && other.nrIngrediente > 0) {
            this->listaIngrediente = new string[nrIngrediente];
            for (int i = 0; i < nrIngrediente; i++) {
                this->listaIngrediente[i] = other.listaIngrediente[i];
            }
        }
        else {
            this->listaIngrediente = nullptr;
            this->nrIngrediente = 0;
        }
    }

    int getId() const {
        return id;
    }

    static int getNrArticole() {
        return nrArticole;
    }

    string getNume() const {
        return nume;
    }

    float getPret() const {
        return pret;
    }

    int getNrBucati() const {
        return nrBucati;
    }

    int getNrIngrediente() const {
        return nrIngrediente;
    }

    const string* getListaIngrediente() const {
        return listaIngrediente;  
    }


    void setNume(const string& nume) {
        this->nume = nume;
    }

    void setPret(float pret) {
        this->pret = pret;
    }

    void setNrBucati(int nrBucati) {
        this->nrBucati = nrBucati;
    }

    void setListaIngrediente(const string* ingrediente, int nrIngredienteNou) {
        // eliberam memoria veche
        delete[] this->listaIngrediente;

        if (ingrediente != nullptr && nrIngredienteNou > 0) {
            this->nrIngrediente = nrIngredienteNou;
            this->listaIngrediente = new string[nrIngredienteNou];

            for (int i = 0; i < nrIngredienteNou; i++) {
                this->listaIngrediente[i] = ingrediente[i];
            }
        }
        else {
            this->listaIngrediente = nullptr;
            this->nrIngrediente = 0;
        }
    }

    void setNrIngrediente(int nrIngredienteNou) {
        // doar actualizam valoarea fara modificarea listea
        this->nrIngrediente = nrIngredienteNou;
    }

    Articol& operator=(const Articol& other) {
        if (this != &other) {
            this->nume = other.nume;
            this->pret = other.pret;
            this->nrBucati = other.nrBucati;
            delete[] listaIngrediente;

            this->nrIngrediente = other.nrIngrediente;
            if (nrIngrediente > 0 && other.listaIngrediente != nullptr) {
                listaIngrediente = new string[nrIngrediente];
                for (int i = 0; i < nrIngrediente; ++i) {
                    listaIngrediente[i] = other.listaIngrediente[i];
                }
            }
            else {
                listaIngrediente = nullptr;
            }
        }
        return *this;
    }

   

    void AfisareArticol() const {
        cout << "Articol " << id << ": " << nume << ", Pret: " << pret
            << " RON, Bucati: " << nrBucati << "\nIngrediente:";
        if (listaIngrediente != nullptr) {
            for (int i = 0; i < nrIngrediente; i++) {
                cout << " " << listaIngrediente[i];
            }
        }
        else {
            cout << " Fara ingrediente.";
        }
        cout << endl;
    }

    friend ostream& operator<<(ostream& out, const Articol& a) {
        out << "Articol: ID=" << a.id
            << ", Nume=" << a.nume
            << ", Pret=" << a.pret
            << ", Bucati=" << a.nrBucati
            << ", Ingrediente=(";

        if (a.listaIngrediente && a.nrIngrediente > 0) {
            for (int i = 0; i < a.nrIngrediente; i++) {
                out << a.listaIngrediente[i];
                if (i < a.nrIngrediente - 1) out << ", ";
            }
        }
        else {
            out << "Fara ingrediente";
        }

        out << ")]";
        return out;
    }
};

int Articol::nrArticole = 0;

class Magazin {
private:

    const int id;
    static int nrMagazine;
    string nume;
    string adresa;
    Angajat* administrator;
    int nrArticole;
    Articol* articole;
    

public:
    ~Magazin() {
        delete administrator;
        delete[] articole;
    }

    Magazin() : id(++nrMagazine) {
        this->nume = "Necunoscut";
        this->adresa = "Necunoscuta";
        this->administrator = nullptr;
        this->articole = nullptr;
        this->nrArticole = 0;
    }

    Magazin(const string& nume, const string& adresa, const Angajat& admin, const Articol* articoleInput, int nrArticole) : id(++nrMagazine) {
        this->nume = nume;
        this->adresa = adresa;
        this->nrArticole = nrArticole;
        this->administrator = new Angajat(admin);

        if (nrArticole > 0 && articoleInput != nullptr) {
            this->articole = new Articol[nrArticole];
            for (int i = 0; i < nrArticole; ++i) {
                this->articole[i] = articoleInput[i];
            }
        }
        else {
            this->articole = nullptr;
            this->nrArticole = 0;
        }
    }

    Magazin(const Magazin& other) : id(++nrMagazine) {
        this->nume = other.nume;
        this->adresa = other.adresa;
        this->nrArticole = other.nrArticole;
        this->administrator = other.administrator ? new Angajat(*other.administrator) : nullptr;

        if (other.articole != nullptr && nrArticole > 0) {
            this->articole = new Articol[nrArticole];
            for (int i = 0; i < nrArticole; ++i) {
                this->articole[i] = other.articole[i];
            }
        }
        else {
            this->articole = nullptr;
        }
    }

    int getId() const {
        return id;
    }

    static int getNrMagazine() {
        return nrMagazine;
    }

    string getNume() const {
        return nume;
    }

    string getAdresa() const {
        return adresa;
    }

    Angajat* getAdministrator() const {
        return administrator;
    }

    int getNrArticole() const {
        return nrArticole;
    }

    const Articol* getArticole() const {
        return articole;
    }
    void setNume(const string& numeNou) {
        this->nume = numeNou;
    }

    void setAdresa(const string& adresaNoua) {
        this->adresa = adresaNoua;
    }

    void setAdministrator(const Angajat& adminNou) {
        // stergem administratorul vechi
        delete this->administrator;

        // Copiem obiectul
        this->administrator = new Angajat(adminNou);
    }

    void setArticole(const Articol* articoleNoi, int nrArticoleNoi) {
        // Curatam vechile articole
        delete[] this->articole;

        if (articoleNoi != nullptr && nrArticoleNoi > 0) {
            this->nrArticole = nrArticoleNoi;
            this->articole = new Articol[nrArticoleNoi];
            for (int i = 0; i < nrArticoleNoi; ++i) {
                this->articole[i] = articoleNoi[i];
            }
        }
        else {
            this->articole = nullptr;
            this->nrArticole = 0;
        }
    }

    void setNrArticole(int nrNou) {
        // seteaza doar numarul  nu modifica lista
        this->nrArticole = nrNou;
    }

    void Afisare() const {
        cout << "Magazinul " << id << ": " << nume << ", " << adresa << "\nAdministrator: ";
        if (administrator) {
            cout << administrator->getNume();
        }
        else {
            cout << "Fara administrator";
        }
        cout << "\nArticole: ";
        if (articole) {
            for (int i = 0; i < nrArticole; ++i) {
                cout << articole[i].getNume() << " ";
            }
        }
        else {
            cout << "Niciun articol.";
        }
        cout << "\n\n";
    }
};

int Magazin::nrMagazine = 0;

int main() {
    Angajat angajat1;
    Angajat angajat2("Popescu", "Ion", "1234567890000", "Administrator");
    Angajat angajat3("Ionescu", "Maria", "2123456789000");

    cout << angajat1 << endl;
    angajat2.AfisareAngajat();
    angajat3.AfisareAngajat();

    string ingrediente[] = { "Faina", "Apa", "Sare" };
    Articol articol1("Paine", 5.5f, 100, ingrediente, 3);
    Articol articol2;
    Articol articol3 = articol1;

    articol1.AfisareArticol();
    articol2.AfisareArticol();
    articol3.AfisareArticol();

    Articol lista[] = { articol1, articol2 };
    Magazin m1("Mega Image", "Bd. Unirii", angajat2, lista, 2);
    m1.Afisare();

    Magazin m2 = m1;
    m2.Afisare();

    return 0;
}
