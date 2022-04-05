#include <iostream>
using namespace std;

int licz(int x) {
    int w;
    if(x == 1) {
        return 1;
    } else {
        w = licz(x / 2);
        if(x % 2 == 1) {
            return w + 1;
        } else {
            return w - 1;
        }
    }
}

int main()
{
    int liczba;
    cout << "Podaj liczbe: " << '\n';
    cin >> liczba;
    cout << "Po funkcji: " << licz(liczba);
}