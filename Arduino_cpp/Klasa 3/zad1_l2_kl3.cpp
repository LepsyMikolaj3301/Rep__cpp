#include<iostream>
#include<vector>
#include<math.h>

using namespace std;

vector<int> dzielniki_liczby(int ponczus) {
    vector<int>dzielniki;
    for(int j = 1; j < ponczus; j++) {
        if(ponczus % j == 0) {
            cout << "to jest dzielnik: " << j << '\n';
            dzielniki.push_back(j);
        }
    }
    return dzielniki;
}

int main() {
    int liczba_uzyt, n, zmienna1 = 1;
    vector<int> liczby_koniec, wyszukane_dzielniki;
    cout << "Podaj liczbe, a my wypiszemy liczby doskonale!\n";
    cin >> liczba_uzyt;
    for(int i = liczba_uzyt; i > 1; i--) {
        wyszukane_dzielniki = dzielniki_liczby(i);
        for(int l = 0; l < wyszukane_dzielniki.size(); l++) {
            zmienna1 *= wyszukane_dzielniki[l];
        }
        cout << "zmienna1 to: " << zmienna1 << '\n';
        if(i == zmienna1) {
            liczby_koniec.push_back(zmienna1);
            cout << "mm\n";
        }
        wyszukane_dzielniki.clear();
        zmienna1 = 1;
        cout << i <<"\n";
    }
    cout << "Liczby doskonale w tym zakresie to:\n";
    for(int i:liczby_koniec) {
    cout << "liczba:" << i << "\n";
    }


}
/*
liczba n
n > 1
liczba = a*b*c
a,b,c = dzielniki liczby
a < n > b itd

podana liczba > n
dla każdej liczby n < podana liczba

program wyszukuje dzielniki liczby n
później te dzielniki zostają od najmniejszej do największej mnożone i sprawdzane


*/
