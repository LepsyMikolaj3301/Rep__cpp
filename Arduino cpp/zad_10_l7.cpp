#include <iostream>
#include <vector>

using namespace std;

int najm(vector<int>liczby) {
    int najm = liczby[0];
    for(int i:liczby) {
        if(najm > i) {
            najm = i;
        }
    }
    return najm;
}

int main() {
    int liczba;
    int m = 15;
    vector<int>dane;
    while(m) {
        cin >> liczba;
        dane.push_back(liczba);
        m--;
    }
    cout << "Najmniejsza liczba w tym wektorze to: " << najm(dane);
}