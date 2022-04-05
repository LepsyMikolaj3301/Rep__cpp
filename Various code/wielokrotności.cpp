#include <iostream>
using namespace std;

void wielokrotnosci(int x) {
    for (int i = 0; i < 20; i++)
    {
        cout << x * i << " ";
    }
    
}

int main() {
	int n;
	cout<<"Podaj liczbe naturalna: ";
	cin>>n;
	wielokrotnosci(n);
	return 0;
}
