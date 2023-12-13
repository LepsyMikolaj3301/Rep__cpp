#include <iostream>
#include <time.h>
using namespace std;


int main() {

    srand(time(NULL));

    char c;
    int n, liczba_wazna;
    
    int najw = 0;
    cout << "Podaj ile liczb chcesz wylosowac: " << '\n';
    cin >> n;
    cout << "----------------------\n";
    int *tablica1=new int[n]; //alokacjaaaaaaaaaaaaaaaaaaaaaaaaa
    for( int i = 0; i < n; i++) {
        tablica1[i] = rand()%101;
    }
    for( int i = 0; i < n; i++) {
        cout << tablica1[i] << '\n';
    }
    
    cout << "\n----------------------\n";
    for(int i = 0; i < 101; i++ ) {
        cout << tablica1[i] << ' ';
    }
    cout << "\n----------------------\n";
    while(true) {
        cout << "Podaj liczbe do sprawdzenia: " << '\n';
        cin >> liczba_wazna;
        cout << "Liczbe " << liczba_wazna << " wylosowano: " << '\n';
        cout << "Skonczyc sprawdzanie? (wcisnij: t, aby zakonczyc ; wcisnij: n , aby sprawdzac dalej)\n";
        cin >> c;
        if(c == 't') {
            break;
        }
        else if(c == 'n') {
            continue;
        }
    }
    delete[]tablica1;
    cout << "dzieki za uzycie programu!";
}