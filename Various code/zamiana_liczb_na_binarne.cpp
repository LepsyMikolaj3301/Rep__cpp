#include <iostream>

//zamiana_liczb_na_binarne.cpp

using namespace std;

int policz_ile(int liczba_dzielona) {
    int i = 0;
    do {
        i++;
        //cout << "Reszta z liczby: " << liczba_dzielona%2 << '\n';
        //cout << "ta liczba:" << liczba_dzielona << '\n';
        liczba_dzielona = liczba_dzielona/2;
    } while(liczba_dzielona != 0);
    return i;
}


int main() {
    int liczba_uzyt, ile_razy = 0, i = 0, tymczas;
    cout << "Podaj liczbe: \n";
    cin >> liczba_uzyt;
    ile_razy = policz_ile(liczba_uzyt);
    int wynik[ile_razy] = {0};
    
    //kod na obliczanie liczby binarnej z danej liczby
    do {
        wynik[i] = liczba_uzyt%2;
        i++;
        liczba_uzyt = liczba_uzyt/2;
    } while(liczba_uzyt != 0);
    cout << "Wynik to\n";
    for(int o = 0; o < ile_razy; o++) {
        tymczas = wynik[o];
    }
    
}