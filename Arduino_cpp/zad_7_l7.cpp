#include <iostream>
#include<vector>
#include<time.h>
#include<string>
using namespace std;

int kontener(vector<int>myvect,int i) {
    bool odpowiedz = false;
    for(int j:myvect) {
        if(i == j) {
            odpowiedz = true;
            break;
        }
    }
    return odpowiedz;
}

int main() {
    srand(time(NULL));
    int i;
    vector<int>myvect;
    cout << "Podaj sprawdzana liczbe: \n";
    cin >> i;
    for(int h = 0;h < 15;h++) {
        myvect.push_back(rand()%101);
        cout << myvect[h] << ' ';
    }
    cout << '\n';
    if(kontener(myvect, i) == 1) {
        cout << "TAK";
    } else {
        cout << "NIE";
    }
    
}