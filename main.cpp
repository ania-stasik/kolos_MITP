#include <iostream>
#include <cstdlib>
#include <vector>
#include <ctime>

using namespace std;


///------tworzę klasę Complex------///
class Complex {
public:
    float re_;
    float im_;

    Complex(float re, float im);                ///definicja konstruktora tej klasy

    void MyConj(Complex temp) {      ///metoda zamieniająca liczbę zespoloną na sprzężoną.
        im_ = im_ * -1;        ///??????///this->im_ = this->im_ * -1;
    }
};

///----deklaracja konstruktora klasy Complex---//
Complex::Complex(float re, float im) {
    re_ = re;
    im_ = im;
}

///----przypisywanie wartości losowych do tablicy--///
void losowe(float *array) {
    for (int i = 0; i < 7; i++) {
        array[i] = rand() % 10;
    }
}

int main() {
    const int N = 7;            ///deklaracja stałej N

    ///deklaracja dwóch tablic
    float array1[N];
    float array2[N];

    ///srand dla poprawnego działania funkcji rand()
    srand(time(NULL));

    ///deklaracja tablicy typu Complex
    vector<Complex> tablica_l_zesp;
    vector<Complex> tablica_l_sprz;

    ///wpisywanie losowych liczb do tablicy
    losowe(array1);
    losowe(array2);

    ///wyświetlanie zawartości tablicy nr1
    cout << "Wartosci tablicy 1: ";
    for (int i = 0; i < N; i++) {
        cout << array1[i] << ", ";
    }
    cout << endl;

    ///wyświetlanie zawartości tablicy 2
    cout << "Wartosci tablicy 2: ";
    for (int i = 0; i < N; i++) {
        cout << array2[i] << ", ";
    }
    cout << endl;


    ///przypisywanie do tablicy i utworzenie kolejnych obiektów klasy Complex
    for (int i = 0; i < N; i++) {
        Complex temp(array1[i], array2[i]);
        tablica_l_zesp.push_back(temp);
    }

    ///przypisywanie do tablicy i utworzenie kolejnych obiektów klasy Complex, sprzężone
    for (int i = 0; i < N; i++) {
        Complex temp(tablica_l_zesp[i].re_, tablica_l_zesp[i].im_);
        tablica_l_sprz.push_back(temp);
        tablica_l_sprz[i].MyConj(temp);
    }

    ///Wyświetlanie wszystkich elementów wszystkich obiektów
    cout << "RE:    IM: " << endl;
    cout<<"Tablica l.zesp: "<<endl;
    for (int i = 0; i < N; i++) {
        cout << tablica_l_zesp[i].re_ << "\t" << tablica_l_zesp[i].im_ << endl;
    }
    cout<<"Tablica l.sprz: "<<endl;
    for (int i = 0; i < N; i++) {
        cout << tablica_l_sprz[i].re_ << "\t" << tablica_l_sprz[i].im_ << endl;
    }
}