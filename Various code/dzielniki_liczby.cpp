#include <iostream>

using namespace std;

bool czy_pierwsza(int n) {
    if(n<2) {
        return false;
    }

    for(int i=2;i*i<=n;i++) {
        if(n%i==0) {
            return false;
        }
    }
    return true;
}

int main() {
    int liczba, iterajnik = 0, index = 0, index2 = 0;
    cout << "Podaj liczbe: ";
    cin >> liczba;
    
    for(int i=0; i < liczba; i++) {
        if(czy_pierwsza(i)) {
            iterajnik++;
        }
    }
    //zainicjowanie tablicy liczb pierwszych
    int tab_pierwszych[iterajnik];

    for(int i=0; i < liczba; i++) {
        if(czy_pierwsza(i)) {
            tab_pierwszych[index] = i;
            index++;
        }
    }
    cout << "Liczby pierwsze to: \n";
    for(int i=0; i < iterajnik; i++) {
        cout << tab_pierwszych[i] << '\n';
    }

    //zmienne z ostatnimi liczbami
    int skladnia_liczby[liczba] = {0};
    int itr_skl_lb = 0;
    int wielkosc = liczba;

    //znalezienie liczb pierwszych w liczbie
    while(liczba > 1) {
        if(liczba%tab_pierwszych[index2] == 0) {
            liczba = liczba/tab_pierwszych[index2];
            skladnia_liczby[itr_skl_lb] = tab_pierwszych[index2];
            itr_skl_lb++;
        } else {
            index2++;
        }
    }

    cout << "Liczba jaka podales sklada sie z iloczynu liczb: \n";
    for(int i=0; i < wielkosc; i++) {
        if(skladnia_liczby[i] != 0)
            cout << skladnia_liczby[i] << '\n';
    }
}