#include <iostream>
#include <string>
using namespace std;

string wieze( int n, char x, char y, char z) {
    string proces = "";
    if( n == 1 ) {
        cout << x << " -> " << y << "\n";
    } else {
        wieze(n - 1, x, z, y);
        cout << x << " -> " << y << '\n';
        wieze(n - 1, z, y, x);
    }
}

int main() {
    int n;
    char x = 'X', y = 'Y', z = 'Z';
    cout << "Podaj n: " << '\n';
    cin >> n;
    wieze( n, x, y, z);
}