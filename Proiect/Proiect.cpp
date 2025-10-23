// Alexandra-Maria Neacsu Articol A, Magazin M, Angajat N;
#include <string>
#include <iostream>
#include <stdexcept>
#include <cstring>
#include <vector>
#include <sstream>
#include <fstream>

using namespace std;


class Angajat;
class Articol;


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
    ~Magazin() {
        if (this->articole != nullptr) {
            delete[] this->articole;
        }
        if (this->administrator != nullptr) {
            delete this->administrator;
        }
    }

    Magazin() : id(++nrMagazine) {
        this->administrator = nullptr;
        this->nume = "Necunoscut";
        this->adresa = "Necunoscuta";
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
    ~Angajat() {
        if (this->functie != nullptr) {
            delete[] this->functie;
        }
        nrAngajati--;
    }

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
    ~Articol() {
        if (this->listaIngrediente != nullptr) {
            delete[] this->listaIngrediente;
        }
    }

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
            for (int i = 0; i < nrIngrediente; ++i) listaIngrediente[i] = ingrediente[i];
        }
    }

    // operator= pentru a permite copierea în Magazin
    Articol& operator=(const Articol& o) {
        if (this != &o) {
            nume = o.nume;
            pret = o.pret;
            nrBucati = o.nrBucati;
            delete[] listaIngrediente;
            nrIngrediente = o.nrIngrediente;
            if (nrIngrediente > 0 && o.listaIngrediente) {
                listaIngrediente = new string[nrIngrediente];
                for (int i = 0; i < nrIngrediente; ++i) listaIngrediente[i] = o.listaIngrediente[i];
            }
            else {
                listaIngrediente = nullptr;
            }
        }
        return *this;
    }

    // (opțional) copy ctor
    Articol(const Articol& o)
        : id(++totalArticole), nume(o.nume), pret(o.pret),
        listaIngrediente(nullptr), nrIngrediente(o.nrIngrediente),
        nrBucati(o.nrBucati) {
        if (nrIngrediente > 0 && o.listaIngrediente) {
            listaIngrediente = new string[nrIngrediente];
            for (int i = 0; i < nrIngrediente; ++i) listaIngrediente[i] = o.listaIngrediente[i];
        }
    }
};
int Articol::totalArticole = 0;


int main() {
    std::cout << "Hello World!\n";
    return 0;
}