#include<iostream>
#include<conio.h>
#include<vector>
using namespace std;

int main() {
    vector<int>vect1(20, 2);
    vector<int>vect2(20, 1);
    for(int k:vect1,vect2) {
        cout << k << ' ';
    }
}