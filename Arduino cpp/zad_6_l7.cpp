#include <iostream>


using namespace std;

int main() {
    int n;
    int a;
    int ile = 0;
    cout << "Podaj ile liczb chcesz wciskac: \n";
    cin >> n;
    int tablica[n];
    for(int i = 0; i < n; i++) {
        cin >> tablica[i];
    }
    cout <<  "Podaj a : " << '\n';
    cin >> a;
    for(int i = 0; i < n; i++ ) {
        if(a == tablica[i]) {
            ile++;
        }
    } 
    cout << "\na pojawilo sie: " << ile << " razy";
}