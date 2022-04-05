#include <iostream>
#include <vector>
#include <time.h>

using namespace std;

int main() {
    srand(time(0));
    int i,j,m;
    vector<int>myvect;
    cout << "Podaj i , potem j: \n";
    cin >> i >> j;
    while(20) {
        myvect.push_back(rand()%50);
    }
}