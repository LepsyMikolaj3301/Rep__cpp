#include <iostream>

using namespace std;

int main() {
    int lekcje[5];
    cout << "Podaj ilosc lekcji w poszczegolnych dniach tygodnia: \n" <<
    "1. Poniedzialek\n2. Wtorek\n3. Sroda\n4. Czwartek\n5. Piatek\n";
    for(int i = 0; i < 5; i++) {
        cout << "Dzien tygodnia: " << i + 1 << "\nPodaj ilosc lekcji: \n";
        cin >> lekcje[i];
    }
    for(int i = 0; i < 5; i++) {
        cout << "Dzien tygodnia: " << i + 1 << "\n" << "Masz tyle: " << lekcje[i] << " lekcji!\n";
    }
}