#include <iostream>
#include <time.h>
#include <conio.h>
#include <vector>

using namespace std;
void generowanie_randomowych_objektow(char mapa[10][10],int poziom_mapy) {
    
}
void wypisanie(char mapencja[10][10]) {    
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            cout << mapencja[i][j] << ' ';
        }
    cout << '\n';
    }
}
void generowanie_pustej_mapy(char nowa_mapa[10][10]) {
    for(int i = 0; i < 10; i++) {
                        for(int j = 0; j < 10; j++) {
                            if((i == 0 || i == 9) && (j > 0 && j < 9)) nowa_mapa[i][j] = '-';
                            else if((i == 0 || i == 9) && (j == 0 || j == 9)) nowa_mapa[i][j] = '.';
                            else if((i > 0 && i < 9) && (j == 0 || j == 9)) nowa_mapa[i][j] = '|';
                            else nowa_mapa[i][j] = '*';
                        }
                }
}

int main() {
    srand(time(0));
    int m = 5;
    int poziom_mapy = 1;
    char mapa1[10][10];
    generowanie_pustej_mapy(mapa1);
    int poz_x_gracz = 1;
    int poz_x_met = 9;
    int ilosc_krzakow;
    // @ będzie w randomowym miejscu (wartosc x gracza jest zawsze taka sama = to jest int poz_x_gracz)
    int poz_y_gracza = rand()%8 + 1;
    mapa1[poz_y_gracza][1] = '@';
    
    // Meta będzie losowana
    int rand_poz_mety = rand()%8 + 1;

    mapa1[rand_poz_mety][8] = 'M';
    
    // krzaczki będą generowane randomowo
    int wybranie_los_wart_x_krzak, wybranie_los_wart_y_krzak;
    vector<int> poz_x_krzak;
    vector<int> poz_y_krzak;
    
    /* 
        łatwy lvl = 15 krzaczków
        średni lvl = 25 krzaczków
        ciężki lvl = 35 krzaczków
    */
    if(poziom_mapy == 1) {
        ilosc_krzakow = 15;
    } else if (poziom_mapy == 2)
    {
        ilosc_krzakow = 25;
    } else if(poziom_mapy == 3) {
        ilosc_krzakow = 35;
    }  
    // [ 64 ->]
    // [64 ->  ]
    bool pytanie = true;
    for(int i = 0; i < 15; i++) {
        while(pytanie == true) {
            bool czy_wszystko = true;
            bool czy_wart_x = false;
            bool czy_wart_y = false;
            wybranie_los_wart_x_krzak = rand()%8 + 1;
            wybranie_los_wart_y_krzak = rand()%8 + 1;
                // sprawdzanie wartości z metami
                // for(int j : poz_met) {
                //     if(wybranie_los_wart_y_krzak == j) {
                //         czy_wszystko = false;
                //         break;
                //     }
                //     if(wybranie_los_wart_y_krzak == j + 1)
                //         czy_wszystko = false;
                //     if(wybranie_los_wart_y_krzak == j - 1)
                //         czy_wszystko = false;
                //     if(wybranie_los_wart_x_krzak == poz_x_met - 1 && wybranie_los_wart_y_krzak == j) 
                //         czy_wszystko = false;
                // }
                //sprawdzanie wartości z innymi krzakami
            for(int k:poz_x_krzak) {
                if (wybranie_los_wart_x_krzak == k) {
                    czy_wart_x = true;
                    break;
                }
            }
            for(int k:poz_y_krzak) {
                if(wybranie_los_wart_y_krzak == k) {
                    czy_wart_y = true;
                    break;
                }
            }
            if(czy_wart_x == true && czy_wart_y == true) {
                czy_wszystko = false;
            }
            //sprawdzanie wartości z graczem
            if(wybranie_los_wart_x_krzak == poz_x_gracz && wybranie_los_wart_y_krzak == poz_y_gracza){
                czy_wszystko == false;
            }
            if(wybranie_los_wart_x_krzak == poz_x_gracz + 1) {
                czy_wszystko == false;
            }
            if(czy_wszystko == true) {
                mapa1[wybranie_los_wart_y_krzak][wybranie_los_wart_x_krzak] = 'X';
                poz_x_krzak.push_back(wybranie_los_wart_x_krzak);
                poz_y_krzak.push_back(wybranie_los_wart_y_krzak);
                pytanie = false;
            } else if(czy_wszystko == false) {
                pytanie = true;
            }
            for(int i = 0; i < 10; i++) {
                for(int j = 0; j < 10; j++) {
                cout << mapa1[i][j] << ' ';
                }
                cout << '\n';
            }
        }
    pytanie = true;
    }
    cout << "\nKONIEC\n";
    wypisanie(mapa1);
    
    getch();
    
}
