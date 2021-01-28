#include <iostream>

using namespace std;

int stopien;

int main() {
    //podanie stopnia wielomianu
    
    setlocale(LC_ALL, " ");

    float wartosc_x;
    float wynik = 0;
    // stopien wielomianu
    cout << "--------------------------------" << '\n' <<
    "Podaj ile wspolczynnikow ma wielomian: \n";
    cin >> stopien;

    float wspol[stopien];
    //współczynniki wielomianu
    cout << "Podaj wspolczynniki wielomianu\n";

    for(int i = stopien; i >= 0; i--) {
            cout << "a" << i << " = ";
            cin >> wspol[i];    
    }

    for(int i = stopien; i >= 0; i--) {
            if (wspol[i] >= 0 && i != stopien ) {
                    cout << " + ";
            }
        cout << wspol[i];
        if (i > 1) {
            cout << "x^" << i;
        } else if (i == 1)
        {
            cout << "x";
        }
    }

    cout << '\n';
    cout << "Podaj wartosc x: " << '\n';
    cin >> wartosc_x;

    float b = wspol[stopien];

    for(int i = stopien - 1; i >= 0; i--) {
        wynik = wspol[i] + b*wartosc_x;
        b = wynik;
    }
    cout << "--------------------------------" << '\n';
    cout << "Wynik wielomianu dla x = " << wartosc_x << " to: " << wynik << '\n';

}