#include <iostream>

using namespace std;

void dzielniki(int m) {
    for(int i = 1; i <= m; i++ ) {
        if(m%i == 0) cout << i << " ";
    }
}

int main() {
    int n;
    cout << "Podaj liczbe naturalna: ";
    cin >> n;
    cout << "Dzielniki naturalne liczby " << n << " to: ";
    dzielniki(n);
}