#include <iostream>
#include<vector>

using namespace std;
vector<int>szukane(vector<int>vectorix) {
    int dzielnik;
    vector<int>dane;
    cout << "Podaj dzielnik\n";
    cin >> dzielnik;
    for(int i:vectorix) {
        if(i%dzielnik == 0) {
            dane.push_back(i);
        }
    }
    return dane;
}
int main() {
    vector<int>myvect;
    int liczba;
    cout << "Wprowadź kilka liczb, po wprowadzeniu 0, wprowadzanie się zakończy\n";
    while(true) {
        if(liczba != 0) {
            cin >> liczba;
            myvect.push_back(liczba);
        } else {
            break;
        }
    }
    vector<int>koncowe = szukane(myvect);
    for(int i:koncowe) {
        cout << "Liczba podzielna: " << i << '\n';
    }
}