#include <iostream>
#include <time.h>
#include <vector>
#include <string>
using namespace std;

void wstep1() {
    cout << "Dla rozwiazania z tablica, napisz: T" << '\n';
    cout << "Dla rozwiazania z wektorem, napisz: W" << '\n';
}

int main() {
    setlocale(LC_ALL, " ");
    srand(time(NULL));

    char wybor;
    wstep1();
    cin >> wybor;

    switch (wybor)
    {
    case 'T':
        int tablica1[50];
        int tablica2[100];
        for(int i = 0; i < 51; i++ ) {
            tablica1[i] = rand()%101;
        }
        for(int i = 0; i < 51; i++ ) {
            cout << tablica1 << ' ';
        }
        cout << '\n';
        for(int i = 0; i < 101; i++) {
            tablica2[tablica1[i]]++;
        }
        for(int i = 0; i < 101; i++) {
            if(tablica2[i] != 0) {
                cout << i << " - " << tablica2[i] << '\n';
            }
        }
        break;
    
    case 'W':
        vector <int> myvect;
        int licz_los;
        for(int i = 0; i < 51; i++ ) {
            licz_los = rand()%101;
            myvect.push_back(licz_los);
        }
        for(int i:myvect) {
            cout << i << ' ';
        }
        cout << '\n';
        
        break;
    }
}