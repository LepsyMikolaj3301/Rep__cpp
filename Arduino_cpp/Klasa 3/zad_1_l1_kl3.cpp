#include <iostream>
#include <conio.h>

using namespace std;

int main() {
    int liczba;
    bool pierwsza_czy;

    while(true) {
    pierwsza_czy = true;
    cout << "Podaj liczbe: \n";
    cin >> liczba;
    for(int i = 2; i < liczba; i++) {
        if(liczba % i == 0) {
            cout << "Liczba ta jest podzielna przez " << i << '\n';
            pierwsza_czy = false;
            break;
        }
    }

    if(pierwsza_czy == true)
        cout << "Liczba ta jest liczba pierwsza\n";

    if (getch() == 't') {
        break;
    }
    }
}
