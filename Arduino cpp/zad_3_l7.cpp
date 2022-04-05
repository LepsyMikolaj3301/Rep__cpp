#include<iostream>
#include<vector>
using namespace std;

int main() {
    int wybor, wartosc;
    int tab[10];
    vector <int> myvect;
    cout << "1. Uzycie tablicy\n" << "2. Uzycie vektoru\n";
    cin >> wybor;

    switch (wybor)
    {
    case 1:
        for(int i = 0; i < 10; i++) {
            cout << "Podaj wartosc komorki numer: " << i << '\n';
            cin >> tab[i];
        }
        for(int i = 0; i < 10; i++) {
            cout << tab[i] << ' ';
        }
        cout << "\n-----\n";
        cout << "odwrocone\n";
        for(int i = 9; i >= 0; i--) {
            cout << tab[i] << ' ';
        }
        cout << "\nKONIEC";
        break;
    
    case 2:
        for(int i = 0; i < 10; i++) {
            cout << "Wartosc " << i+1 << " vectora" << '\n';
            cin >> wartosc;
            myvect.push_back(wartosc);
        }
        cout << "- - - -" << '\n';
        for(int i:myvect){
            cout << i << '\n';
        }
        cout << "\nodwrocenie\n \n";
        for(int i = myvect.size() - 1;i >= 0; i--) {
            cout << myvect[i] << '\n';
        }
        cout << "Koniec";
        break;
    }
}