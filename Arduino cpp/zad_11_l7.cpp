#include <iostream>
#include <vector>
#include <time.h>

using namespace std;

vector<int>dodatnie(vector<int>vect) {
    vector<int>dodat;
    for(int i:vect) {
        if(i > 0) {
            dodat.push_back(i);
        }
    }
    return dodat;
}

int main() {
    srand(time(0));
    int n;
    cout << "Podaj wielkosc wektora: \n";
    cin >> n;
    vector<int>myvect(n);

    for(int i;i < n;i++) {
        myvect[i] = rand()%101 - 50;
    }
    for(int i:myvect) {
        cout << i << '\n';
    }
    vector<int>koniec = dodatnie(myvect);
    for(int i:koniec) {
        cout << i << ' ';
    }
}