// Alexandra-Maria Neacsu  -  Articol A, Magazin M, Angajat N

#include <iostream>
#include <string>
#include <cstring>   // pentru strcpy_s
using namespace std;

class Magazin;
class Angajat;
class Articol;

// Functii globale (prietene) – declarate dinainte
float valoareTotalaStoc(const Magazin& m);
void aplicaDiscount(Magazin& m, float procent);

class Angajat {
private:
    const int id;
    static int nrAngajati;

    string nume;
    string prenume;
    string cnp;      // CNP pe 13 cifre, îl păstrăm ca string
    char* functie;   // alocat dinamic

public:
    // Destructor – eliberăm memoria din HEAP
    ~Angajat() {
        if (functie != nullptr) {
            delete[] functie;
            functie = nullptr;
        }
        nrAngajati--;
    }

    // Constructor implicit
    Angajat()
        : id(++nrAngajati), nume("Necunoscut"), prenume("Necunoscut"),
        cnp("0000000000000") {
        functie = new char[strlen("Necunoscut") + 1];
        strcpy_s(functie, strlen("Necunoscut") + 1, "Necunoscut");
    }

    // Constructor cu parametri
    Angajat(const string& nume, const string& prenume,
        const string& cnp, const char* functie)
        : id(++nrAngajati), nume(nume), prenume(prenume), cnp(cnp) {
        this->functie = new char[strlen(functie) + 1];
        strcpy_s(this->functie, strlen(functie) + 1, functie);
    }

    // Constructor de copiere
    Angajat(const Angajat& other)
        : id(++nrAngajati) {
        nume = other.nume;
        prenume = other.prenume;
        cnp = other.cnp;

        if (other.functie != nullptr) {
            functie = new char[strlen(other.functie) + 1];
            strcpy_s(functie, strlen(other.functie) + 1, other.functie);
        }
        else {
            functie = nullptr;
        }
    }

  

    
};

// Definire atribut static
int Angajat::nrAngajati = 0;


class Articol {
private:
    const int id;
    static int nrArticole;

    string nume;
    float pret;
    string* listaIngrediente; // vector alocat dinamic
    int nrIngrediente;
    int nrBucati;

    // Functiile globale au acces la private
    friend float valoareTotalaStoc(const Magazin& m);
    friend void aplicaDiscount(Magazin& m, float procent);

public:
    // Destructor – eliberăm HEAP
    ~Articol() {
        if (listaIngrediente != nullptr) {
            delete[] listaIngrediente;
            listaIngrediente = nullptr;
        }
        nrArticole--;
    }

    // Constructor implicit
    Articol()
        : id(++nrArticole), nume("Necunoscut"), pret(0),
        listaIngrediente(nullptr), nrIngrediente(0), nrBucati(0) {}

    // Constructor cu parametri (inclusiv ingrediente)
    Articol(const string& nume, float pret, int nrBucati,
        const string* ingrediente = nullptr, int nrIngrediente = 0)
        : id(++nrArticole), nume(nume), pret(pret),
        nrIngrediente(nrIngrediente), nrBucati(nrBucati) {
        if (nrIngrediente > 0 && ingrediente != nullptr) {
            listaIngrediente = new string[nrIngrediente];
            for (int i = 0; i < nrIngrediente; i++) {
                listaIngrediente[i] = ingrediente[i];
            }
        }
        else {
            listaIngrediente = nullptr;
            this->nrIngrediente = 0;
        }
    }

    // Constructor de copiere
    Articol(const Articol& other)
        : id(++nrArticole) {
        nume = other.nume;
        pret = other.pret;
        nrBucati = other.nrBucati;
        nrIngrediente = other.nrIngrediente;

        if (other.listaIngrediente != nullptr && nrIngrediente > 0) {
            listaIngrediente = new string[nrIngrediente];
            for (int i = 0; i < nrIngrediente; i++) {
                listaIngrediente[i] = other.listaIngrediente[i];
            }
        }
        else {
            listaIngrediente = nullptr;
            nrIngrediente = 0;
        }
    }

 

   
};

// Definire atribut static
int Articol::nrArticole = 0;

class Magazin {
private:
    string nume;
    const int id;
    static int nrMagazine;
    static int codCaen;     

    string adresa;
    Angajat* administrator; // 
    Articol* articole;      // vector dinamic de articole
    int nrArticole;

    // Functii prietene
    friend float valoareTotalaStoc(const Magazin& m);
    friend void aplicaDiscount(Magazin& m, float procent);

public:
    // Destructor – ștergem din HEAP
    ~Magazin() {
        if (administrator != nullptr) {
            delete administrator;
            administrator = nullptr;
        }
        if (articole != nullptr) {
            delete[] articole;
            articole = nullptr;
        }
        nrMagazine--;
    }

    // Constructor implicit
    Magazin()
        : nume("Necunoscut"), id(++nrMagazine),
        adresa("Necunoscuta"), administrator(nullptr),
        articole(nullptr), nrArticole(0) {}

    // Constructor cu parametri
    Magazin(const string& nume, const string& adresa,
        const Angajat& admin,
        const Articol* articole, int nrArticole)
        : nume(nume), id(++nrMagazine),
        adresa(adresa), nrArticole(nrArticole) {
        administrator = new Angajat(admin);

        if (nrArticole > 0 && articole != nullptr) {
            this->articole = new Articol[nrArticole];
            for (int i = 0; i < nrArticole; i++) {
                this->articole[i] = articole[i]; // folosește copy
            }
        }
        else {
            this->articole = nullptr;
            this->nrArticole = 0;
        }
    }

    // Constructor de copiere
    Magazin(const Magazin& other)
        : nume(other.nume), id(++nrMagazine),
        adresa(other.adresa), nrArticole(other.nrArticole) {

        if (other.administrator != nullptr) {
            administrator = new Angajat(*other.administrator);
        }
        else {
            administrator = nullptr;
        }

        if (other.articole != nullptr && nrArticole > 0) {
            articole = new Articol[nrArticole];
            for (int i = 0; i < nrArticole; i++) {
                articole[i] = other.articole[i];
            }
        }
        else {
            articole = nullptr;
            nrArticole = 0;
        }
    }

};

// Definire atribute statice
int Magazin::nrMagazine = 0;
int Magazin::codCaen = 4724;



// 1. Calculează valoarea totală a stocului dintr-un magazin
float valoareTotalaStoc(const Magazin& m) {
    float suma = 0;
    for (int i = 0; i < m.nrArticole; i++) {
        suma += m.articole[i].pret * m.articole[i].nrBucati;
    }
    return suma;
}

// 2. Aplică un discount (%) tuturor articolelor din magazin
void aplicaDiscount(Magazin& m, float procent) {
    for (int i = 0; i < m.nrArticole; i++) {
        m.articole[i].pret = m.articole[i].pret * (1 - procent / 100.0f);
    }
}


int main() {
    // Test Angajat
    Angajat a1("Popescu", "Ion", "1234567890123", "Administrator");
    

    Angajat a2 = a1;  // constructor de copiere
   

    // Test Articol
    string ingr1[] = { "Faina", "Apa", "Drojdie" };
    Articol art1("Paine", 5.0f, 100, ingr1, 3);

    string ingr2[] = { "Zahar", "Arome" };
    Articol art2("Suc", 4.5f, 50, ingr2, 2);

    // Vector de articole pentru magazin
    Articol listaArticole[] = { art1, art2 };


    // Test Magazin
    Magazin m1("Magazin Central", "Str. Principala nr.1", a1, listaArticole, 2);

   
    return 0;
}
