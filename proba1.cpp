#include<iostream>
using namespace std;

int main() {
    int wybor;
    cout << "Liczba tablic: ";
    cin >> wybor;
    int **tablica1 = new int *[wybor];
    for (int i = 0; i<wybor; i++)
		tablica1[i] = new int [2];
    for(int i = 0; i<wybor; i++){
        for(int j = 0; j<2; j++) {
            tablica1[i][j] = 69;
            cout << tablica1[i][j] << ' ';
        }
        cout << '\n';
    }
    for (int i = 0; i<wybor; i++)
        delete[] tablica1[i];
    delete[]tablica1;
}