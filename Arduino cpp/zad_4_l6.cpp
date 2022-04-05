#include <iostream>
using namespace std;

double tab1[] = {1.3, 4, -2.2, 6, 8.8, 9};


double pokaz_tablice(double tab1[], int n) {
    
    double maxymilian = tab1[0];

    for(int i = 0; i<n; i++) {
        cout <<  "  " << tab1[i] << "    \n";
        if( tab1[i] > maxymilian) {
            maxymilian = tab1[i];
        }
    }
    
    return maxymilian;
}

int main() {
    int liczba;
    cout << "Ile liczb chcesz pokazac?" << '\n';
    cin >> liczba;
    cout << pokaz_tablice(tab1, liczba);
}
