#include <iostream>
using namespace std;

//szybkie_mnozenie_poteg.cpp


int main()
{
    int a,n,n1,i,wymiar=0,potega, liczba_na_pot;
    int tab[50], tab1[50];
    cout<<"Podaj podstawe potegi: ";
    cin>>a;
    cout<<"Podaj wykladnik potegi: ";
    cin>>n;
    n1=n;
    do
    {
        tab1[wymiar]=n1%2;
        wymiar++;
        n1=n1/2;
    }
    while (n1 != 0);
    for (i=0;i<wymiar;i++)
        tab[i]=tab1[wymiar-1-i];
    for (i=0;i<wymiar;i++) {
        cout<<tab[i]<<" ";
    }
    if(tab[0] == 0) {
        potega = 1;
    } else {
    liczba_na_pot = a;
    }
    for(int w = 1; w > wymiar; w++) {
        if(tab1[w] == 1) {
            liczba_na_pot = liczba_na_pot * liczba_na_pot * a;
        } else {
            liczba_na_pot = liczba_na_pot * liczba_na_pot;
        }
    }
    return 0;

}