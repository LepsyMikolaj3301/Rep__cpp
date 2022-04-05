#include<iostream>

using namespace std;

int silnia(int zmienna) {
    if(zmienna == 0) {
        return 1;
    } else {
        return zmienna *= silnia(zmienna - 1);
    }
}

int main() {
    int zmienna;
    cout << "Podaj jaka wartosc ma byc w silni: " << '\n';
    cin >> zmienna;
    cout << "Silnia wynosi: " << silnia(zmienna);
}