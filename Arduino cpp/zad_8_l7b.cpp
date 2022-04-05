#include <iostream>
#include <vector>

using namespace std;

vector<int> szukajnik(vector<int>liczby) {
    vector<int>parzyste;
    for(int i:liczby) {
        if(i%2 == 0) {
            parzyste.push_back(i);
        }
    }
    return parzyste;
}

int main() {
    vector<int> liczby;
    int liczbunka;
    while(true) {
        cout << "Podaj liczbe wektora: \n (po wprowadzeniu 0, skończy się wprowadzanie)\n";
        cin >> liczbunka;
        if(liczbunka == 0) {
            break;
        } else {
            liczby.push_back(liczbunka);
        }
    }
    cout << '\n';
    vector<int> koncowka = szukajnik(liczby);
    for(int i:koncowka) {
        cout << i << ' ';
    }
}