#include <iostream>
#include <vector>

using namespace std;

bool czy_pierwsza(int n) {
    if(n<2) {
        return false;
    }

    for(int i=2;i*i<=n;i++) {
        if(n%i==0) {
            return false;
        }
    }
    return true;
}

vector<int>cyfry_liczby(int liczba_podana) {
    int pomocnicza1 = liczba_podana;
    while(true) {
        
    }



}

int main() {



}