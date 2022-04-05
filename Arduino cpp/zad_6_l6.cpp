#include <iostream>
#include <time.h>
using namespace std;



void pokaz_tablice(int tab[]) {
    for(int i = 0; i < 50; i++) {
        cout << tab[i] << " dla:"<< "   " << i << '\n';
    }
}

int main() {
    srand(time(NULL));
    int tablica1[50];

    for(int i = 0; i < 50; i++) {
        tablica1[i] = rand()%101;
    }
    pokaz_tablice(tablica1);
    int tablica2[101] = {0};
    // sprawdzanie
    for(int i = 0; i < 50; i++ ) {
        tablica2[tablica1[i]]++;
    }
    cout << " - - - - - - - - - - - - - " << '\n';

    cout << " - - - - - - - - - - - - - " << '\n';
    //pokazanie największej wartości
    int najw = 0;
    int ktora;
    for(int i = 0; i < 50; i++ ) {
        if(tablica2[i] > najw){
            najw = tablica2[i];
            ktora = i;
        }
    }
    cout << najw << "   dla   " << ktora << '\n';
    cout << " - - - - - - - - - - - - - " << '\n';
}