#include <iostream>
#include <time.h>
using namespace std;

int main() {
    srand(time(NULL));
    int tab1[20];
    for( int i; i < 101; i++) {
        tab1[i] =  rand()%101;
        cout << ' ' << tab1[i] << '\n';
    }

    // suma wyrazów parzystych

    int suma_wyr_parz = 0;
    for( int i; i < 21; i++) {
        if(tab1[i]%2 == 0) {
            suma_wyr_parz = suma_wyr_parz + tab1[i];
        }
    }

    //suma wyrazów nieparzystych

    int suma_wyr_nieparz = 0;
    for( int i; i < 21; i++) {
        if(tab1[i]%2 != 0) {
            suma_wyr_nieparz = suma_wyr_nieparz + tab1[i];
        }
    }

    //suma wyrazów o parzystych indeksach

    int suma_wyr_parz_ind = 0;
    for( int i; i< 21; i++) {
        if(i%2 == 0) {
            suma_wyr_parz_ind = suma_wyr_parz_ind + tab1[i];
        }
    }

    //suma wyrazów o nieparzystych indeksach

    int suma_wyr_nieparz_ind = 0;
    for( int i; i< 21; i++) {
        if(i%2 != 0) {
            suma_wyr_nieparz_ind = suma_wyr_nieparz_ind + tab1[i];
        }
    }

    //sumę wyrazów o numerach od 1 do n/2,
    int suma_wyr_do_n2 = 0;
    int liczba1 = 20/2 + 1;
    for( int i; i<liczba1; i++ ) {
        suma_wyr_do_n2 = suma_wyr_do_n2 + tab1[i];
    }

    //sumę wyrazów o numerach od (n/2)+1 do n

    int suma_wyr_do_n2_1 = 0;
    int liczba2 = 20/2 + 1;
    for( int i = liczba2; i<21; i++) {
        suma_wyr_do_n2_1 = suma_wyr_do_n2_1 + tab1[i];
    }

    // wypisanie

    cout << suma_wyr_parz << '\n';
    cout << suma_wyr_nieparz << '\n';
    cout << suma_wyr_parz_ind << '\n';
    cout << suma_wyr_nieparz_ind << '\n';
    cout << suma_wyr_do_n2 << '\n';
    cout << suma_wyr_do_n2_1 << '\n';
}