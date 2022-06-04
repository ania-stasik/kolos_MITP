#include <iostream>
#include <vector>

using namespace std;

///-------------tworzę klasę o nazwie Produkt----------------
class Produkt {
public:
    string nazwa_ = "Nowy_produnkt";
    int kod_;
    float cena_;

    Produkt(string nazwa, int kod);     ///deklaracja konstruktora

    void odkoduj_cene(int kod);     ///deklaracja metody (funkcji składowej)
};
///---------------------------------------------------------------------------------------

void Produkt::odkoduj_cene(int kod) {       ///definicja metody, liczenie ceny produktu
    cena_ = kod / 888;
}

Produkt::Produkt(string nazwa, int kod) {       ///definicja konstruktora klasy
    nazwa_ = nazwa;
    kod_ = kod;
    odkoduj_cene(kod);
}

///---tworzę klasę o nazwie Produkt_na_wage dziedziczonej po klasie Produkt
class Produkt_na_wage : public Produkt {
public:
    float cena_kg_;
    float waga_;

    void oblicz_cene(float cena_kg, float waga);        ///deklaracja metody oblicz_cene
    Produkt_na_wage(float cena_kg, float waga, string nazwa, int kod) : Produkt(nazwa, kod) {
        cena_kg_ = cena_kg;
        waga_ = waga;
        oblicz_cene(cena_kg_, waga_);                    /// wywolanie metody przez konstruktor
    }
};
///----------------------------------------------------------------------------------------------

void Produkt_na_wage::oblicz_cene(float cena_kg,
                                  float waga) {      ///definicja metody, oraz wyliczenie ceny produktu na wage
    cena_ = cena_kg * waga;
};

void wyswietl(
        Produkt x) {                          ///definicja funkcji wywołanej obiektem klasy Produkt i wypisująca dane produktu
    cout << "Nazwa: " << x.nazwa_ << endl;
    cout << "Cena: " << x.cena_ << "zl" << endl;
    cout << "Kod produktu: " << x.kod_ << endl;
    cout << endl;
}

void wyswietl(Produkt_na_wage x) {
    cout << "Nazwa: " << x.nazwa_ << endl;
    cout << "Cena: " << x.cena_ << "zl" << endl;
    cout << "Kod produktu: " << x.kod_ << endl;
    cout << "Waga produktu: " << x.waga_ << "kg" << endl;
    cout << "Cena za kilogram: " << x.cena_kg_ << "zl" << endl;
    cout << endl;
}

int main() {

    ///-------tworze obiekty klasy Produkt i Produkt_na_wage-----------
    Produkt p1("Woda", 123456);
    Produkt p2("Sok", 456788);
    Produkt p3("Cukierki", 717171);
    Produkt_na_wage pnw1(2, 4, "Banany", 222222);
    Produkt_na_wage pnw2(7, 2, "Jablka", 999999);

    ///----wyswietlam dane o produktach-----------
    wyswietl(p1);
    wyswietl(p2);
    wyswietl(p3);
    wyswietl(pnw1);
    wyswietl(pnw2);

    ///tworze tablice typu Produkt
    vector<Produkt> P;

    ///przypisuje elementy do tablicy typu Produkt
    P.push_back(p1);
    P.push_back(p2);
    P.push_back(p3);

    ///Wyswietlam skladowe wszystkich elementow tablicy
    cout << "Nazwa: " << P[0].nazwa_ << ", Cena: " << P[0].cena_ << ", Kod: " << P[0].kod_ << endl;
    cout << "Nazwa: " << P[1].nazwa_ << ", Cena: " << P[1].cena_ << ", Kod: " << P[1].kod_ << endl;
    cout << "Nazwa: " << P[2].nazwa_ << ", Cena: " << P[2].cena_ << ", Kod: " << P[2].kod_ << endl;


    return 0;
}
