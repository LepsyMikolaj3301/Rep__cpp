#include <iostream>
#include <time.h>
using namespace std;

int main() {
    
    int n, razy, zamiana;
    
    cout << "Podaj wielkosc tablicy: " << '\n';
    cin >> n;
    int *tablica1 = new int[n];

    for( int i = 0; i < n; i++ ) {
        tablica1[i] = rand()%21;
    }

    cout << "Podaj liczbe zamiany: " << '\n';
    cin >> razy;
    cout << "---------------------\n";
    
    for(int i = 0; i < n; i++) {
            cout << tablica1[i] << ' ';
        }
    cout << '\n';
    while(razy) {
        for(int i = 0; i < n - 1; i++ ) {
            zamiana = tablica1[i];
            tablica1[i] = tablica1[i + 1];
            tablica1[i + 1] = zamiana;
            }
        
        for(int i = 0; i < n; i++) {
            cout << tablica1[i] << ' ';
        }
        cout << '\n';
        razy--;
    }
}