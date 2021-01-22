#include<iostream>
#include<math.h>
using namespace std;

//    program_na_pierwiastek_wielomianu.cpp

int stopien;

void informacje() {
    cout << "--- WITAJ ---" << '\n'
    << "Podaj stopien wielomianu, a my policzymy czy ma pierwiastki! " << '\n' <<
    "Stopien: " << '\n';
    cin >> stopien;
}



int main() {
    informacje();
    int wspol[stopien];
    cout << "Podaj wspolczynniki wyrazenia algebraicznego: " << '\n'
    << "(jest to BETA programu, dziala tylko dla twierdzenia o pierwiastkach calkowitych (nie wpisuj na poczatek np. a = 3 bałwanie)) " << '\n';
        // wpisanie wspolczynników
    for(int i = stopien; i >= 0; i--) {
            cout << "a" << i << " = ";
            cin >> wspol[i];           
        }
           
    cout << '\n' << " --------------------------- " << '\n' << "| ";
        //wypisanie wyrażenia
    for(int i = stopien; i >= 0; i--) {
        if (wspol[i] >= 0 && i != stopien ) {
                cout << " + ";
            }
        cout << wspol[i];
        if (i > 1) {
            cout << "x^" << i;
        } else if (i == 1)
        {
            cout << "x";
        }
    }
    cout << " |" << '\n';
    cout << " --------------------------- " << '\n';
    // q to jest an , p to jest a0
    int q = wspol[stopien], p = sqrt(pow(wspol[0],2)),p_q = p/q, counter1 = 0,counter2 = 0;
    // sprawdzamy dzielniki p
    for(int i = 1; i <= p; i++) {
        if(p%i == 0) {
            counter1++;
        }
    }
    for(int i = 1; i <= q; i++) {
        if(q%i == 0) {
            counter2++;
        }
    }
    
    
    counter1 = counter1 * 2;
    counter1--;
    counter2--;
    int counter3 = counter1;
    
    int dzielniki[counter1];
    int tab2[counter2];
    counter1 = 0;
    counter2 = 0;
    for(int i = 1; i <= p; i++) {
        if(p%i == 0) {
            dzielniki[counter1] = i;
            counter1++;
        }
    }
    for(int i = 1; i <= p; i++) {
        if(p%i == 0) {
            dzielniki[counter1] = -i;
            counter1++;
        }
    }
    for(int i = 1; i <= q; i++) {
        if(q%i == 0) {
            tab2[counter2] = i;
            counter2++;
        }
    }

    
    int wynik = 0, w = 0;
    int pierwiastki[counter3];
    // algorytm sprawdzający czy lewa == 0
    for(int i = 0; i <= counter3; i++){
        wynik = pow(dzielniki[i], stopien);
        for(int k = stopien - 1; k >= 0; k--) {
            wynik = pow(dzielniki[i], k) * wspol[k] + wynik;
        }
        cout << "f(" << dzielniki[i] << ") = " << wynik << '\n';
        if (wynik == 0) {
            pierwiastki[w] = dzielniki[i];
            w++;
        }
    }
    //wypisywanie pierwiastków
    cout << '\n' << "Pierwiastki tego wielomianu (nie wszystkie) to: " << '\n';
    for(int i = 0; i <= w; i++) {
        if(pierwiastki[i] != 0) {
            cout << " x" << i << " = " << pierwiastki[i] << '\n';
        }
    }
}