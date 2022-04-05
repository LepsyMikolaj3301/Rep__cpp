#include <iostream>
#include <vector>
#include<time.h>
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
    srand(time(NULL));
    int zmienna;
    cout << "Podaj wielkośc wektora: " << '\n';
    cin >> zmienna;
    vector<int>liczby;
    while(zmienna) {
        liczby.push_back(rand()%101 + 50);
        zmienna--;
    }
    for(int i:liczby) {
        cout << i << ' ';
    }
    cout << '\n';
    vector<int> koncowe = szukajnik(liczby);
    for(int i:koncowe) {
        cout << i << ' ';
    }
}