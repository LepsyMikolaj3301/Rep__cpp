#include <iostream>

using namespace std;

int main() {

    int *sumsum = new int; //alokuje

    *sumsum = 0;

    for(int i=1;i < 101; i++) {
        *sumsum += i;
        cout << *sumsum <<'\n';
    }
    cout << "Ostatecznie wychodzi: " << *sumsum;
    delete sumsum;
}