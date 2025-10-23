// Alexandra-Maria Neacsu Articol A, Magazin M, Angajat N;
#include <string>
#include <iostream>
#include <cstring>
#include <vector>
#include <sstream>

using namespace std;




class Magazin {
private:
    string nume;
    const int id;
    static int nrMagazine;
    static int codCaen;
    string adresa;
    Angajat* administrator;
    Articol* articole;
    static int nrArticole;

public:


    Magazin() : id(++nrMagazine) {
        this->administrator = nullptr;
        this->nume = "Necunoscut";
        this->adresa = "Necunoscuta";
        this->articole = nullptr;
        Magazin::nrArticole = 0;
    }

    Magazin(string adresa, int nrArt)
        : id(++nrMagazine) {
        this->adresa = adresa;
        this->nume = "Necunoscut";
        this->administrator = nullptr;
        this->articole = nullptr;
        Magazin::nrArticole = 0;
    }

    Magazin(string adresa, int nrArt, const Articol* lista)
        : id(++nrMagazine) {
        this->adresa = adresa;
        this->nume = "Necunoscut";
        this->administrator = nullptr;

        int n = (nrArt < 0 ? 0 : nrArt);
        if (n > 0 && lista != nullptr) {
            this->articole = new Articol[n];
            for (int i = 0; i < n; i++) {
                this->articole[i] = lista[i];
            }
        }
        else {
            this->articole = nullptr;
        }
        Magazin::nrArticole = n;
    }

    ~Magazin() {
        if (this->articole != nullptr) {
            delete[] this->articole;
        }
        if (this->administrator != nullptr) {
            delete this->administrator;
        }
    }
};

//  pentru static members initializare
int Magazin::nrMagazine = 0;
int Magazin::codCaen = 4724;
int Magazin::nrArticole = 0;


class Angajat {
private:
    const int id;
    static int nrAngajati;
    string nume;
    string prenume;
    long long CNP;
    char* functie;

public:
   

    Angajat() : id(++nrAngajati) {
        this->nume = "Necunoscut";
        this->prenume = "Necunoscut";
        this->CNP = 0;
        this->functie = new char[std::strlen("Necunoscut") + 1];
        std::strcpy(this->functie, "Necunoscut");
    }

    Angajat(string nume, string prenume, long long CNP, const char* functie)
        : id(++nrAngajati) {
        this->nume = nume;
        this->prenume = prenume;
        this->CNP = CNP;
        this->functie = new char[std::strlen(functie) + 1];
        std::strcpy(this->functie, functie);
    }


    Angajat(string nume, string prenume, long long CNP)
        : id(++nrAngajati) {
        this->nume = nume;
        this->prenume = prenume;
        this->CNP = CNP;
        this->functie = new char[std::strlen("Necunoscut") + 1];
        std::strcpy(this->functie, "Necunoscut");
    }
    ~Angajat() {
        if (this->functie != nullptr) {
            delete[] this->functie;
        }
        nrAngajati--;
    }
};
int Angajat::nrAngajati = 0;


class Articol {
private:
    const int id;
    static int totalArticole;
    string nume;
    float pret;
    string* listaIngrediente;
    int nrIngrediente;
    int nrBucati;

public:
    

    Articol()
        : id(++totalArticole), nume("Necunoscut"), pret(0.0f),
        listaIngrediente(nullptr), nrIngrediente(0), nrBucati(0) {}

    Articol(string nume, float pret)
        : id(++totalArticole), nume(nume), pret(pret < 0 ? 0.0f : pret),
        listaIngrediente(nullptr), nrIngrediente(0), nrBucati(0) {}

    Articol(string nume, float pret, int buc, const string* ingrediente, int nIngr)
        : id(++totalArticole), nume(nume), pret(pret < 0 ? 0.0f : pret),
        listaIngrediente(nullptr), nrIngrediente(nIngr < 0 ? 0 : nIngr),
        nrBucati(buc < 0 ? 0 : buc) {
        if (nrIngrediente > 0 && ingrediente != nullptr) {
            listaIngrediente = new string[nrIngrediente];
            for (int i = 0; i < nrIngrediente; ++i)
                listaIngrediente[i] = ingrediente[i];
        }
    }
    ~Articol() {
        if (this->listaIngrediente != nullptr) {
            delete[] this->listaIngrediente;
        }
    }

 

   
};
int Articol::totalArticole = 0;


int main() {
    
    return 0;
}