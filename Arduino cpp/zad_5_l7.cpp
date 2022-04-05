#include<iostream>
#include<vector>
using namespace std;

int main() {
    int ile;
    int liczba;
    vector<int>myvect;
    cout << "Podaj ile liczb bedzie: \n";
    cin >> ile;

    int *tablica = new int [ile];
    for(int i = 0; i < ile; i++) {
        cout << "podaj liczbe: ";
        cin >> tablica[i];
    }
    //wypisanie od tyłu
    cout << "\nwypisanie od tylu\n";
    for(int i = ile - 1; i >= 0; i--) {
        cout << tablica[i] << ' ';
    }
    cout << "\n- - -" << '\n';
    while(ile != 0) {
        cout << "Podaj liczbe: ";
        cin >> liczba;
        myvect.push_back(liczba);
        ile--;
    }
    cout << '\n';
    for(int i = myvect.size() - 1; i >= 0; i--) {
        cout << myvect[i] << '\n';
    }

    delete[]tablica;
}