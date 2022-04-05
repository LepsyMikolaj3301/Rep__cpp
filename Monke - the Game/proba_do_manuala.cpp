#include <iostream>
#include <string>
#include <tchar.h>
using namespace std;

void manual_przycisk(string przycisk) {
    cout << "/";
    for(int i = 0; i < przycisk.length() + 2; i++ ) {
        cout << "=";
    }
    cout << "\\" << '\n';
    cout << "| " << przycisk << " |" << '\n';
    cout << "\\";
    for(int i = 0; i < przycisk.length() + 2; i++ ) {
        cout << "=";
    }
    cout << "/" << '\n';
}

int main() {
    string przycisk[5] = {"w", "a", "s", "d", "SPACJA"};
    string info = "==KONIEC GRY==";
    for(int i = 0; i < 5; i++) {
    manual_przycisk(przycisk[i]);
    cout << '\n';
    }
    manual_przycisk(info);
}