#include <iostream>
#include <conio.h>

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

int suma(int uzyt) {
    int suma = 0;
    int liczb = uzyt, razy = 0;
    for(; liczb > 1; razy++) {
        liczb/=10;
    }
    for(int i = 1; i < razy; i++) {
        suma += uzyt%(i*10);
        uzyt /= (i*10);
    }
    return suma;
}
/*

*/
int main() {
    int liczba_uzyt, ile_razy, suma_liczb;
    cout << "Podaj liczbe: \n";
    cin >> liczba_uzyt;
    cout << "Suma cyfr liczby " << liczba_uzyt << " to " << suma(liczba_uzyt) << '\n';
    if(czy_pierwsza(suma(liczba_uzyt)) == true) {
        cout << "Liczba ta jest pierwsza";
    } else {
        cout << "Liczba ta nie jest liczba pierwsza";
    }
    


}